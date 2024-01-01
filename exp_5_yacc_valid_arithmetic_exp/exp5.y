%{
//Program: Recognize a valid arithmetic expression using Yacc

#include <stdio.h>
%}
%token NUMBER ID
// setting the preferences
// and associativity of operators
%left '+' '-'
%left '*' '/'
%left '%'
%right '^'
%%
E : T  {
                                   printf("\nExpression is valid\n");
                                   return 0;
                        }

T :
       T '+' T { $$ = $1 + $3; }
       | T '-' T { $$ = $1 - $3; }
       | T '*' T { $$ = $1 * $3; }
       | T '/' T { $$ = $1 / $3; }
       | T '%' T { $$ = $1 % $3; }
       | T '^' T { 
                      double prod = 1;
                      for(int i = 1; i<=$3; i++) prod = prod*$1;
                      $$ = prod; 
                      }
       | '-' NUMBER { $$ = -$2; }
       | '-' ID { $$ = -$2; }
       | '(' T ')' { $$ = $2; }
       | NUMBER { $$ = $1; }
       | ID { $$ = $1; }
%%

int main() {
       printf("Enter the expression\n");
       yyparse();
}

/* For printing the error messages */
int yyerror(char *s){
       printf("\nExpression is invalid\n");
}

/*
Output:
Enter the expression
5^3

Expression is valid
*/
