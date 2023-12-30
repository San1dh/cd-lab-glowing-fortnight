// Tried a symmetrical string of 0s & 1s using RDP using 0S0 & 1S1 but it got stuck in if loop. Need to find problem & fix later.

#include <stdio.h>

char s[100];
int p = 0;

int S();

int main(void) {
  printf("Hello World, enter a string:\n");
  scanf("%s", s);
  if (S()) {
    printf("\nString accepted\n");
  } else {
    printf("\nInvalid string\n");
  }
  return 0;
}

int S() {
  if (s[p] == '0') {
    printf("yes1");
    p++;
    if (S()) {
      if (s[p] == '0') {
        printf("yes2");
        p++;
        return 1;
      } else
        p--;
        return 0;
    } else
      p--;
    return 0;
  } else if (s[p] == '1') {
    printf("yes1");
    p++;
    if (S()) {
      if (s[p] == '1') {
        printf("yes2");
        p++;
        return 1;
      } else
        p--;
        return 0;
    } else
      p--;
    return 0;
  } else
    return 1;
  // epsilon
}
