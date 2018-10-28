#include <stdio.h>
#define yywrap() (/*CONSTCOND*/1)

extern int yylex();
extern int yylineno;
extern char* yytext;


int main(void)
{
   int ntoken, vtoken;
   ntoken = 1;
   while(ntoken){
       ntoken = yylex();
   }
   return 0;
}