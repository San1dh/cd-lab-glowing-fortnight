%{
int i=0;
%}

%%

[" "]|[.] {i++;}

%%

int main(){
yyin = fopen("text.txt", "r");
yylex();
printf("\nNo. of words: %d\n", i);
return 0;
}

int yywrap(){
return 1;
}
