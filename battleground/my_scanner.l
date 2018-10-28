%{

%}
%option noyywrap
%%
[\t]+ /*Ignore white space */;

is |
am |
are |
were |
was |
be |
being |
been |
do  { printf("%s: is a verb\n", yytext);}

[a-zA-Z]+ { printf("%s: is not a verb\n", yytext);}

.|\n  { ECHO; /*default value */ }
%%

#define yywrap() (/*CONSTCOND*/1)