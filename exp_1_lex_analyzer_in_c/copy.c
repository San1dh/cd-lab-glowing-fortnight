// todo: to identify
// 1) keywords[if, int, else, float, return],
// 2) identifiers,
// 3) numbers,
// 4) relops

/*
progress: done given keywords(+ char), identifiers (with alphabets and numbers
only), numbers (int & decimal), relational operators, arithmetic operators &
some special characters like assignment operator [ = ] , comma [ , ] , semicolon
[ ; ] & circular brackets [ ( , ) ].

Maybe add [ double, while, for, printf, scanf ] keywords to check
{ Google says printf & scanf are not C keywords but a special function in the
<stdio> library }
maybe check for characters or strings or both if possible also maybe check for
assignment operators

Works at identifying most of the main tokens, now need to maybe check the state
& maybe change 'and' conditions to 'if' & also maybe add the identifiers to a
symbol table.
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int copy1() {
  // printf("Hello World\n");
  char str[100];
  printf("Enter a program statement:\n");
  // if helps to prevent unused return warning in scanf
  // (void)scanf("%[^\n]s", str);
  // [ ^ does not work to prevent warning ]
  if (scanf("%[^\n]s", str) == 1) {
    // printf("%s\n\n", str);
  } else {
    printf("failed to read statement\n");
  }
  // printf("%s\n", str);
  // printf("%lu\n", strlen(str));
  printf("\n");
  int f, l;
  f = 0;
  l = 0;
  while (f < strlen(str)) {
  // printf(" %d ", f);
  // keywords below
  keyif:
    if (str[f] == 'i') {
      if (str[f + 1] == 'f') {
        if (str[f + 2] == ' ' || str[f + 2] == '\n' || str[f + 2] == '\0') {
          printf("keyword 'if'\n");
          f += 3;
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
            if (str[f + 4] == ' ' || str[f + 4] == '\n' || str[f + 4] == '\0') {
              printf("keyword 'else'\n");
              f += 5;
              continue;
            } else
              goto identifiers;
          } else
            goto identifiers;
        } else
          goto identifiers;
      } else
        goto identifiers;
    }
  keychar:
    if (str[f] == 'c') {
      if (str[f + 1] == 'h') {
        if (str[f + 2] == 'a') {
          if (str[f + 3] == 'r') {
            if (str[f + 4] == ' ' || str[f + 4] == '\n' || str[f + 4] == '\0') {
              printf("keyword 'else'\n");
              f += 5;
              continue;
            } else
              goto identifiers;
          } else
            goto identifiers;
        } else
          goto identifiers;
      } else
        goto identifiers;
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
    // nalla code alle? 😏 reply
    //
    // space below
    // space:
    // if (str[f] == ' ') {
    //   f++;
    //   continue;
    // }
  // identifiers below
  identifiers:
    if (isalpha(str[f])) {
      l = f;
      f++;
      // while(isalpha(str[f]) || str[f] == '_')
      while (isalnum(str[f])) {
        f++;
      }
      printf("identifier '");
      for (int i = l; i < f; i++) {
        printf("%c", str[i]);
      }
      printf("'\n");
      continue;
    }
    // assignment operator below
    if (str[f] == '=' &&
        (str[f + 1] == ' ' || isalnum(str[f + 1]) || str[f + 1] == '.' ||
         str[f + 1] == '\'' || str[f + 1] == '\"' || str[f + 1] == '+' ||
         str[f + 1] == '-')) {
      printf("assignment operator '='\n");
      f++;
      continue;
    }
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
    // brackets below
    if (str[f] == '(') {
      printf("special character opening bracket '('\n");
      f++;
      continue;
    }
    if (str[f] == ')') {
      printf("special character closing bracket ')'\n");
      f++;
      continue;
    }
    // increment & decrement operators
    if (str[f] == '+' && str[f + 1] == '+' && isalnum(str[f + 2])) {
      printf("pre-increment operator '++'\n");
      f = f + 2;
      continue;
    }
    if (isalnum(str[f]) && str[f + 1] == '+' && str[f + 2] == '+') {
      printf("post-increment operator '++'\n");
      f = f + 2;
      continue;
    }
    if (str[f] == '-' && str[f + 1] == '-' && isalnum(str[f + 2])) {
      printf("pre-decrement operator '++'\n");
      f = f + 2;
      continue;
    }
    if (isalnum(str[f]) && str[f + 1] == '-' && str[f + 2] == '-') {
      printf("post-decrement operator '++'\n");
      f = f + 2;
      continue;
    }
    // numbers below
    if (isdigit(str[f]) || (str[f] == '.' || str[f] == '+' || str[f] == '-') &&
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
    // maybe arithmetic operators below
    if (str[f] == '+' && (isalnum(str[f + 1]) || str[f + 1] == '-')) {
      printf("arithmetic operator plus '+'\n");
      f++;
      continue;
    }
    if (str[f] == '-' && (isalnum(str[f + 1]) || str[f + 1] == '+')) {
      printf("arithmetic operator minus '-'\n");
      f++;
      continue;
    }
    if (str[f] == '*' && isalnum(str[f + 1])) {
      printf("arithmetic operator multiply '*'\n");
      f++;
      continue;
    }
    if (str[f] == '/' && isalnum(str[f + 1])) {
      printf("arithmetic operator divide '/'\n");
      f++;
      continue;
    }
    if (str[f] == '^' && isalnum(str[f + 1])) {
      printf("arithmetic operator exponent '^'\n");
      f++;
      continue;
    }
    if (str[f] == '%' && isalnum(str[f + 1])) {
      printf("arithmetic operator modulus '%%'\n");
      f++;
      continue;
    }
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
    // switch (str[f]) {
    // case ' ':
    //   f++;
    //   break;
    // default:
    //   f++;
    // }

    // printf("%d ", f);
  }
  printf("\n");
  return 0;
}
