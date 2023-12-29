#include <stdio.h>
#define MAX 1000

char s[MAX];
char *p = s;

int S();
int A();
int B();

/*
Grammar:
  L = {a^2n b^m | n > 0, m >= 0}

  S -> aaAB
  A -> aaA | epsilon
  B -> bB | epsilon
*/

int main() {
  printf("Enter a string:\n");
  scanf("%s", s);
  if (S() & (*p == '$'))
    printf("Successfully parsed\n");
  else
    printf("Invalid string\n");
  return 0;
}

int S() {
  if (*p == 'a') {
    p++;
    if (*p == 'a') {
      p++;
      if (A()) {
        if (B()) {
          return 1;
        }
      }
    }
  }
  return 0;
}

int A() {
  if (*p == 'a') {
    p++;
    if (*p == 'a') {
      p++;
      if (A()) {
        return 1;
      } else
        return 0;
    } else
      return 0;
  } else {
    return 1;
  }
  // return 0;
}

int B() {
  if (*p == 'b') {
    p++;
    if (B()) {
      return 1;
    } else
      return 0;
  } else {
    return 1;
  }
  // return 0;
}

/*
O/P

Enter a string:
aab$
Successfully parsed

Enter a string:
aabb$
Successfully parsed

Enter a string:
aaaaabb$
Invalid string

*/
