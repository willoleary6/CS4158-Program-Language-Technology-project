%{

#include "y.tab.h"
%}


%option noyywrap


%%
[\t\n]+                     /*Ignore white space */;
(?i:BEGINING)               {   return BEGINING;    }
(?i:BODY)                   {   return BODY;    }
(?i:END)                    {   return END; }
[Xx]+                       { 
                                yylval.size = strlen(yytext); 
                                return NUMSIZE; 
                            }
(?i:MOVE)                   {   return MOVE;    }
(?i:TO)                     {   return TO;  }
(?i:ADD)                    {   return ADD; }
(?i:INPUT)                  {   return INPUT;   }
(?i:PRINT)                  {   return PRINT;   }
;                           {   return SEMICOLON;   }
[0-9]+                      { 
                                yylval.size = atoi(yytext); 
                                return INTEGER; 
                            }
[A-Za-z][A-Za-z0-9\-]*      {  
                                yylval.id = yytext; 
                                return IDENTIFIER;
                            }
\"(\\.|[^"\\])*\"           {   return TEXT;    }
\.                          {   return TERMINATOR;  }
.                           {   return 0;   }
%%

#define yywrap() (/*CONSTCOND*/1)
