%{
  /*
  Program: Lexical Analyzer using Lex Tool

  Three Parts of the Lex File: 
  Declaration, 
  Translation Rules & 
  Auxiliary Procedure

  Input File:
  int a = 3.14;

  Output:
  int => Keyword

  a => Identifier

  = => Operator

  3.14 => Number

  ; => Special Character
  */
%}

%%

if|int|for|float|char|return|for {printf("\n%s => Keyword\n", yytext);}
[a-z|A-Z][a-z|A-Z|0-9]* {printf("\n%s => Identifier\n", yytext);}
[>|<|>=|<=|==|!=|=|+|-|/|*] {printf("\n%s => Operator\n", yytext);}
[+|-]*[0-9|.]+ {printf("\n%s => Number\n", yytext);}
'[^']*' {printf("\n%s => Literal\n", yytext);}
  /* [" "] {printf("\n%s => Space\n", yytext);} */
[{|}|,|(|)|[|]|;|] {printf("\n%s => Special Character\n", yytext);}
.|\n {ECHO;}

%%

int main(){
yyin = fopen("input.txt", "r");
yylex();
return 0;
}

int yywrap(){
return 1;
}
