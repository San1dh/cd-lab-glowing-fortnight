#include <stdio.h>
#include <string.h>

struct prod_rules {
  char lhs;
  char rhs[100];
};
struct prod_rules rules[100];
int prod_count = 0;

int main() {
  // printf("Hello World\n");
  char str[100];
  int top = -1;
  FILE *fp;
  fp = fopen("grammar.txt", "r");
  printf("Grammar: \n");
  while (!feof(fp)) {
    fscanf(fp, "%c -> %s\n", &rules[prod_count].lhs, rules[prod_count].rhs);
    printf("%c -> %s\n", rules[prod_count].lhs, rules[prod_count].rhs);
    prod_count++;
  }
  // printf("%d", prod_count);
  printf("\nEnter the string: ");
  scanf("%s", str);
  char stack[100];
  char ch = '$';
  strncat(str, &ch, 1);
  printf("%s\n", str);
  stack[++top] = '$';
  int pos = 0;
  printf("\nStack\t\tInput\t\tAction\n");
  printf("------------------------------------\n");
  printf("%s\t\t\t%s\t\tShift\n", stack, str);
  // top++;
  stack[++top] = str[pos++];
  while (1) {
    char input[100];
    strcpy(input, "");
    strncpy(input, str + (pos), strlen(str) - pos);
    input[strlen(str) - pos] = '\0';
    printf("%s\t\t\t%s\t\t", stack, input);
    if (str[pos] == '$' && stack[top] == 'E' && stack[top - 1] == '$') {
      printf("Accept\n");
      break;
    }
    // printf("hello ");
    int x = 1;
    for (int i = 0; i < prod_count; i++) {
      char copy[100];
      strcpy(copy, "");
      int len = strlen(rules[i].rhs);
      if (top >= len)
        // for (int j = 1; j <= len; j++) {
        //   copy[j] = stack[top - len + j];
        //   printf("%c ", stack[top - len + j]);
        // }
        strncpy(copy, stack + (top - len + 1), len);
      copy[len] = '\0';
      // for (int k = 0; k < strlen(copy); k++)
      //   printf("%c ", copy[k]);
      // printf("%d %d ", top - len + 1, len);
      // x = strcmp(copy, rules[i].rhs);
      // printf("%d %d ", strlen(copy), strlen(rules[i].rhs));
      // printf("%s %s ", copy, rules[i].rhs);
      if (strcmp(rules[i].rhs, copy) == 0) {
        x = 0;
        // printf("Reduce %s\n", stack);
        while (len > 0) {
          stack[top] = ' ';
          top--;
          len--;
        }
        top++;
        stack[top] = rules[i].lhs;
        printf("Reduce %c -> %s\n", rules[i].lhs, rules[i].rhs);
        break;
      }
    }
    if (x == 1) {
      stack[++top] = str[pos++];
      printf("Shift\n");
    }
    // printf("%d ", pos);
    // pos++;
  }
  // printf("%s\t\t\t%s\t\tShift/Reduce\n", stack, str);
  return 0;
}

/*
O/P

Grammar:
E -> E+E
E -> E-E
E -> E*E
E -> E/E
E -> (E)
E -> i

Enter the string: i+i*i
i+i*i$

Stack       Input       Action
------------------------------------
$           i+i*i$      Shift
$i          +i*i$       Reduce E -> i
$E          +i*i$       Shift
$E+         i*i$        Shift
$E+i            *i$     Reduce E -> i
$E+E            *i$     Reduce E -> E+E
$E              *i$     Shift
$E*             i$      Shift
$E*i            $       Reduce E -> i
$E*E            $       Reduce E -> E*E
$E              $       Accept

*/
