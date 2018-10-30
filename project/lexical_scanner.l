%{

%}
%option noyywrap
%%
[\t]+ /*Ignore white space */;

(?i:BEGINING)               { printf("%s:","BEGINING");}
(?i:BODY)                   { printf("%s:"," BODY"); }
(?i:END)                    { printf("%s:"," END"); }
[Xx]+                       { printf("%s:"," NumSize");}
(?i:MOVE)                   { printf("%s:"," MOVE");}
(?i:TO)                     { printf("%s:"," TO"); }
(?i:ADD)                    { printf("%s:"," ADD"); }
(?i:INPUT)                  { printf("%s:"," INPUT");}
(?i:PRINT)                  { printf("%s:"," PRINT"); }
;                           { printf("%s:"," SEMICOLON"); }
[0-9]+                      { printf("%s:"," NUMBER"); }
[A-Za-z][A-Za-z0-9\-]*      { printf("%s:"," STRING");}
\"(\\.|[^"\\])*\"           { printf("%s:"," Non alpha numerics"); }
\.                          { printf("%s:"," Terminate");}
.                           { printf("%s:"," 0"); }
%%

#define yywrap() (/*CONSTCOND*/1)