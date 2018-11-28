%{

#include "y.tab.h"
%}


%option yylineno
%option caseless
%option noyywrap


%%
[\t\n ]+                        /* Ignore whitespace */ ;
BEGINING                        { return BEGINING; }
BODY                            { return BODY; }
END                             { return END; }
MOVE                            { return MOVE; }
TO                              { return TO; }
ADD                             { return ADD; }
INPUT                           { return INPUT; }
PRINT                           { return PRINT; }
;                               { return SEMICOLON; }
X+                              {   
                                    yylval.size = strlen(yytext); 
                                    return NUMSIZE; 
                                }
[0-9]+                          { 
                                    yylval.size = atoi(yytext); 
                                    return INTEGER; 
                                }
[A-Z]+[A-Z0-9\-]*               { 
                                    yylval.id = yytext; 
                                    return VARIABLE; 
                                }
\"[^"\n]*\"                     { 
                                    yylval.id = strdup(yytext); 
                                    return TEXT; 
                                }
[_=+!"£$%^&*()\\\-]+[A-Z0-9\-]* { return *yytext; }
\.                              { return TERMINATOR; }
. ;
%%

