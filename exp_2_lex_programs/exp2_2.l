%{
int j=0;
%}

%%

[a|e|i|o|u|A|E|I|O|U] {j++;}

%%

int main(){
yyin = fopen("text.txt", "r");
yylex();
printf("\nNo. of vowels: %d\n", j);
return 0;
}

int yywrap(){
return 1;
}
