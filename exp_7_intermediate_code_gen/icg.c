#include <stdio.h>
#include <string.h>

struct expressions {
  int id;
  char lhs;
  char exp[10];
} exps[10];

int num = 0;
char str[100];

int main(void) {
  // printf("Hello World\n");
  int n, i;
  // strcpy(str, "a+b-c");
  printf("Input an expression: ");
  fgets(str, 100, stdin);
exp:
  n = strlen(str);
  i = n - 1;
  while (i > 0) {
    if (str[i] == '^') {
      exps[num].id = num;
      strncpy(exps[num].exp, str + (i - 1), 3);
      int a = 65 + num;
      char c = a;
      str[i - 1] = a;
      exps[num].lhs = a;
      for (int j = i; j < n - 1; j++)
        str[j] = str[j + 2];
      str[n - 1] = '\0';
      n = strlen(str);
      i++;
      // str[i] = '';
      // str[i + 1] = '';
      num++;
    }
    i--;
  }
  // printf("%s %s %s \n", exps[0].exp, exps[1].exp, exps[2].exp);
  // printf("%s\n", str);
muldiv:
  n = strlen(str);
  i = 0;
  while (i < n) {
    if (str[i] == '*' || str[i] == '/') {
      exps[num].id = num;
      strncpy(exps[num].exp, str + (i - 1), 3);
      int a = 65 + num;
      char c = a;
      str[i - 1] = a;
      exps[num].lhs = a;
      for (int j = i; j < n - 1; j++)
        str[j] = str[j + 2];
      str[n - 1] = '\0';
      i--;
      num++;
    }
    i++;
  }
  // printf("%d ", count);
  // printf("%s\n", str);
addsub:
  n = strlen(str);
  i = 0;
  while (i < n) {
    if (str[i] == '+' || str[i] == '-') {
      exps[num].id = num;
      strncpy(exps[num].exp, str + (i - 1), 3);
      int a = 65 + num;
      char c = a;
      str[i - 1] = a;
      exps[num].lhs = a;
      for (int j = i; j < n - 1; j++)
        str[j] = str[j + 2];
      str[n - 1] = '\0';
      i--;
      num++;
    }
    i++;
  }
  // printf("%s\n", str);
  printf("\nLHS\t\tValue\n");
  printf("----------------\n");
  for (int i = 0; i < num; i++) {
    printf("%c\t\t%s\n", exps[i].lhs, exps[i].exp);
  }
  return 0;
}

/*
O/P

Input an expression: a+b*c^d

LHS     Value
----------------
A       c^d
B       b*A
C       a+B

*/
