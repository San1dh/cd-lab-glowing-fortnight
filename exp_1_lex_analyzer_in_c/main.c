// todo: to identify
// 1) keywords[if, int, else, float, return],
// 2) identifiers,
// 3) numbers,
// 4) relops

#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct id_table {
  int id;
  char token[100];
} idtab[100];
int idnum = 0;

int main() {
  // printf("Hello World\n");
  char str[100];
  printf("\n");
  int f, l;
  FILE *fp;
  fp = fopen("input.txt", "r");
  if (fp == NULL) {
    printf("The file is not opened. The program will now exit.");
    return 0;
  }
  while (!feof(fp)) {
    f = 0;
    l = 0;
    int state = 0;
    char *x = fgets(str, 100, fp);
    if (x == NULL) {
      // printf("\n\nBlank Line\n\n");
      continue;
    }
    // printf("\n\nLine: %s\n\n", str);
    while (f < strlen(str)) {
    // printf(" %d ", f);
    //
    space:
      if (str[f] == ' ') {
        f++;
        continue;
      }
    // keywords below
    keyif:
      if (str[f] == 'i') {
        if (str[f + 1] == 'f') {
          if (str[f + 2] == ' ' || str[f + 2] == '\n' || str[f + 2] == '\0' ||
              str[f + 2] == '(') {
            printf("keyword 'if'\n");
            f += 3;
            state = 1;
            continue;
          } else
            goto identifiers;
        } else
          goto keyint;
      } else
        goto keyelse;
    keyint:
      if (str[f + 1] == 'n') {
        if (str[f + 2] == 't') {
          if (str[f + 3] == ' ' || str[f + 3] == '\n' || str[f + 3] == '\0') {
            printf("keyword 'int'\n");
            f += 4;
            state = 2;
            continue;
          } else
            goto identifiers;
        } else
          goto identifiers;
      }
    keyelse:
      if (str[f] == 'e') {
        if (str[f + 1] == 'l') {
          if (str[f + 2] == 's') {
            if (str[f + 3] == 'e') {
              if (str[f + 4] == ' ' || str[f + 4] == '\n' ||
                  str[f + 4] == '\0') {
                printf("keyword 'else'\n");
                f += 5;
                state = 3;
                continue;
              } else
                goto identifiers;
            } else
              goto identifiers;
          } else
            goto identifiers;
        } else
          goto keychar;
      }
    keychar:
      if (str[f] == 'c') {
        if (str[f + 1] == 'h') {
          if (str[f + 2] == 'a') {
            if (str[f + 3] == 'r') {
              if (str[f + 4] == ' ' || str[f + 4] == '\n' ||
                  str[f + 4] == '\0') {
                printf("keyword 'else'\n");
                f += 5;
                state = 4;
                continue;
              } else
                goto identifiers;
            } else
              goto identifiers;
          } else
            goto identifiers;
        } else
          goto keyfloat;
      }
    keyfloat:
      if (str[f] == 'f') {
        if (str[f + 1] == 'l') {
          if (str[f + 2] == 'o') {
            if (str[f + 3] == 'a') {
              if (str[f + 4] == 't') {
                if (str[f + 5] == ' ' || str[f + 5] == '\n' ||
                    str[f + 5] == '\0') {
                  printf("keyword 'float'\n");
                  f += 6;
                  state = 5;
                  continue;
                } else
                  goto identifiers;
              } else
                goto identifiers;
            } else
              goto identifiers;
          } else
            goto keyfor;
        } else
          goto keyreturn;
      }
    keyreturn:
      if (str[f] == 'r') {
        if (str[f + 1] == 'e') {
          if (str[f + 2] == 't') {
            if (str[f + 3] == 'u') {
              if (str[f + 4] == 'r') {
                if (str[f + 5] == 'n') {
                  if (str[f + 6] == ' ' || str[f + 6] == '\n' ||
                      str[f + 6] == '\0') {
                    printf("keyword 'return'\n");
                    f += 7;
                    state = 6;
                    continue;
                  } else
                    goto identifiers;
                } else
                  goto identifiers;
              } else
                goto identifiers;
            } else
              goto identifiers;
          } else
            goto identifiers;
        } else
          goto identifiers;
      }
    keyfor:
      if (str[f] == 'f') {
        if (str[f + 1] == 'o') {
          if (str[f + 2] == 'r') {
            if (str[f + 3] == ' ' || str[f + 3] == '(' || str[f + 3] == '\n' ||
                str[f + 3] == '\0') {
              printf("keyword 'for'\n");
              f += 4;
              state = 7;
              continue;
            } else
              goto identifiers;
          } else
            goto identifiers;
        } else
          goto identifiers;
      }
    // identifiers below
    identifiers:
      if (isalpha(str[f])) {
        l = f;
        f++;
        while (isalnum(str[f])) {
          f++;
        }
        state = 8;
        char temp[100];
        strncpy(temp, str + l, f - l);
        temp[f - l] = '\0';
        int flag = 0;
        // printf(" %s %s ", temp, idtab[idnum - 1].token);
        for (int k = 0; k < idnum; k++) {
          if (strcmp(temp, idtab[k].token) == 0) {
            flag = 1;
            break;
          }
        }
        if (flag == 0) {
          strcpy(idtab[idnum].token, temp);
          idtab[idnum].id = idnum;
          // printf(" %s ", idtab[idnum].token);
          idnum++;
        }
        printf("identifier '");
        for (int i = l; i < f; i++) {
          printf("%c", str[i]);
        }
        printf("'\n");
        continue;
      }
    assignment:
      // assignment operator below
      if (str[f] == '=' &&
          (str[f + 1] == ' ' || isalnum(str[f + 1]) || str[f + 1] == '.' ||
           str[f + 1] == '\'' || str[f + 1] == '\"' || str[f + 1] == '+' ||
           str[f + 1] == '-')) {
        state = 9;
        printf("assignment operator '='\n");
        f++;
        continue;
      }
    relational:
      state = 10;
      // relational operators below
      if (str[f] == '=' && str[f + 1] == '=' &&
          (str[f + 2] == ' ' || isalnum(str[f + 2]))) {
        printf("relational operator equals to '=='\n");
        f = f + 2;
        continue;
      }
      if (str[f] == '!' && str[f + 1] == '=' &&
          (str[f + 2] == ' ' || isalnum(str[f + 2]))) {
        printf("relational operator not equals to '!='\n");
        f = f + 2;
        continue;
      }
      if (str[f] == '>' && str[f + 1] == '=' &&
          (str[f + 2] == ' ' || isalnum(str[f + 2]))) {
        printf("relational operator greater than or equals to '>='\n");
        f = f + 2;
        continue;
      }
      if (str[f] == '<' && str[f + 1] == '=' &&
          (str[f + 2] == ' ' || isalnum(str[f + 2]))) {
        printf("relational operator less than or equals to '<='\n");
        f = f + 2;
        continue;
      }
      if (str[f] == '>' && (str[f + 1] == ' ' || isalnum(str[f + 1]))) {
        printf("relational operator greater than '>'\n");
        f++;
        continue;
      }
      if (str[f] == '<' && (str[f + 1] == ' ' || isalnum(str[f + 1]))) {
        printf("relational operator lesser than '<'\n");
        f++;
        continue;
      }
    brackets:
      state = 11;
      // brackets below
      if (str[f] == '(') {
        printf("special character opening circle bracket '('\n");
        f++;
        continue;
      }
      if (str[f] == ')') {
        printf("special character closing circle bracket ')'\n");
        f++;
        continue;
      }
      if (str[f] == '{') {
        printf("special character opening curly bracket '{'\n");
        f++;
        continue;
      }
      if (str[f] == '}') {
        printf("special character closing curly bracket '}'\n");
        f++;
        continue;
      }
    numbers:
      state = 12;
      // numbers below
      if (isdigit(str[f]) ||
          (str[f] == '.' || str[f] == '+' || str[f] == '-') &&
              isdigit(str[f + 1])) {
        l = f;
        f++;
        while (isdigit(str[f]) || str[f] == '.') {
          f++;
        }
        printf("number '");
        for (int i = l; i < f; i++) {
          printf("%c", str[i]);
        }
        printf("'\n");
        continue;
      }
    operators:
      state = 13;
      // maybe arithmetic operators below
      if (str[f] == '+' && (isalnum(str[f + 1]) || str[f + 1] == ' ')) {
        printf("arithmetic operator plus '+'\n");
        f++;
        continue;
      }
      if (str[f] == '-' && (isalnum(str[f + 1]) || str[f + 1] == ' ')) {
        printf("arithmetic operator minus '-'\n");
        f++;
        continue;
      }
      if (str[f] == '*' && (isalnum(str[f + 1]) || str[f + 1] == ' ')) {
        printf("arithmetic operator multiply '*'\n");
        f++;
        continue;
      }
      if (str[f] == '/' && (isalnum(str[f + 1]) || str[f + 1] == ' ')) {
        printf("arithmetic operator divide '/'\n");
        f++;
        continue;
      }
      if (str[f] == '^' && (isalnum(str[f + 1]) || str[f + 1] == ' ')) {
        printf("arithmetic operator exponent '^'\n");
        f++;
        continue;
      }
      if (str[f] == '%' && (isalnum(str[f + 1]) || str[f + 1] == ' ')) {
        printf("arithmetic operator modulus '%%'\n");
        f++;
        continue;
      }
    spec_chars:
      state = 14;
      // special character comma below
      if (str[f] == ',') {
        printf("special character comma ','\n");
        f++;
        continue;
      }
      // special character semicolon below
      if (str[f] == ';') {
        printf("special character semicolon ';' [end of statement]\n");
        f++;
        continue;
      }
      f++;
    }
  }
  printf("\n");
  // printf("%d", idnum);
  printf("ID\t\tToken\n");
  printf("----------------\n");
  for (int k = 0; k < idnum; k++)
    printf("%d\t\t%s\n", idtab[k].id, idtab[k].token);

  return 0;
}

/*
input.txt

int main()
{
  int i=0;
  for(i=0; i<25; i = i + 1) {
    return 1;
  }
}

O/P

keyword 'int'
identifier 'main'
special character opening circle bracket '('
special character closing circle bracket ')'
special character opening curly bracket '{'
keyword 'int'
identifier 'i'
assignment operator '='
number '0'
special character semicolon ';' [end of statement]
keyword 'for'
identifier 'i'
assignment operator '='
number '0'
special character semicolon ';' [end of statement]
identifier 'i'
relational operator lesser than '<'
number '25'
special character semicolon ';' [end of statement]
identifier 'i'
assignment operator '='
identifier 'i'
arithmetic operator plus '+'
number '1'
special character closing circle bracket ')'
special character opening curly bracket '{'
keyword 'return'
number '1'
special character semicolon ';' [end of statement]
special character closing curly bracket '}'
special character closing curly bracket '}'

ID      Token
----------------
0       main
1       i

*/
