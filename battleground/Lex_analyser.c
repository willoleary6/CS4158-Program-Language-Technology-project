#include <stdio.h>
#define yywrap() (/*CONSTCOND*/1)

extern int yylex();
extern int yylineno;
extern char* yytext;

char *names[] = {NULL, "test"};

int main(void)
{
   int ntoken, vtoken;
   ntoken = yylex();
   while(ntoken){
       printf("%d\n", ntoken);
       ntoken = yylex();
   }
   return 0;
}