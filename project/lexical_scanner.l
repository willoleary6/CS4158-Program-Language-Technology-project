%{

%}
%option noyywrap
%%
[\t\n]+ /*Ignore white space */;
^(?i:BEGINING)* |              
^(?i:BODY)*  |                
^(?i:END)*                         { printf("KEYWORD\n");}
[Xx]+                       { printf("Size of num\n");}
(?i:MOVE)                   { printf("MOVE\n");}
(?i:TO)                     { printf("TO\n");}
(?i:ADD)                    { printf("ADD\n");}
(?i:INPUT)                  { printf("INPUT\n");}
(?i:PRINT)                  { printf("PRINT\n");}
;                           { printf("terminator\n");}
[0-9]+                      { printf("Integer\n");}
^[A-Za-z][A-Za-z0-9\-]*     { printf("STRING\n");}
\"(\\.|[^"\\])*\"           { printf("Text of string\n");}
\.                          { printf("Terminate\n");}
.                          
%%

#define yywrap() (/*CONSTCOND*/1)