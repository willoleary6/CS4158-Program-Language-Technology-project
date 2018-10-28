%{

%}
%option noyywrap
%%
[\t]+ /*Ignore white space */;

(?i:BEGINING)               { printf("%s: BEGINING\n");}
(?i:BODY)                   { printf("%s: BODY\n"); }
(?i:END)                    { printf("%s: END\n"); }
[Xx]+                       { printf("%s: NumSize\n");}
(?i:MOVE)                   { printf("%s: MOVE\n");}
(?i:TO)                     { printf("%s: TO\n"); }
(?i:ADD)                    { printf("%s: ADD\n"); }
(?i:INPUT)                  { printf("%s: INPUT\n");}
(?i:PRINT)                  { printf("%s: PRINT\n"); }
;                           { printf("%s: SEMICOLON\n"); }
[0-9]+                      { printf("%s: NUMBER\n"); }
[A-Za-z][A-Za-z0-9\-]*      { printf("%s: STRING\n"); }
\"(\\.|[^"\\])*\"           { printf("%s: Non alpha numerics\n"); }
\.                          { printf("%s: Terminate\n");}
.                           { printf("%s: 0\n"); }

.|\n  { ECHO; /*default value */ }
%%

#define yywrap() (/*CONSTCOND*/1)