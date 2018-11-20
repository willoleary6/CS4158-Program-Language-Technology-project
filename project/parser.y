%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define yywrap() (/*CONSTCOND*/1)
#define NUM_VARIABLES 50

extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern int yylineno;

// prototyping functions
void yyerror(const char *s);
void addVariable(int size, char *name);
void insertNullIntoEndOfString(char *variable);
int isIdentifier(char *variable);
void formatVariable(char *variable);
void checkIfVariableIsIdentifier(char *var);
void moveIntegerToVariable(int num, char *var);
int getIdentifierSize(char *var);
void moveIdentifierToVariable(char *firstVariable, char *secondVariable);


char identifiers[NUM_VARIABLES][32];
int variableCounter = 0;
int sizes[NUM_VARIABLES];
int varCounter = 0;

%}

%union {
        char *id; 
        int size;
    }
%start start
%token <size> INTEGER
%token <size> NUMSIZE
%token <id> IDENTIFIER

%token BEGINING BODY END MOVE TO ADD INPUT PRINT TEXT SEMICOLON TERMINATOR INVALID

%%

start:          BEGINING TERMINATOR declarations 
                {   }

declarations:   declaration declarations 
                {   }   
                | body 
                {   }

declaration:    NUMSIZE IDENTIFIER TERMINATOR 
                { 
                    addVariable($1, $2); 
                }

body:           BODY TERMINATOR code 
                {   }

code:           line code 
                {   }   
                | end 
                {   }

line:           print | input | move | add 
                {   }

print:          PRINT printStatement 
                {   }

printStatement: TEXT SEMICOLON printStatement 
                {   }   
                | IDENTIFIER SEMICOLON printStatement 
                { 
                    checkIfVariableIsIdentifier($1); 
                }
                | TEXT TERMINATOR 
                {   }   
                | IDENTIFIER TERMINATOR 
                { 
                    checkIfVariableIsIdentifier($1); 
                }

input:          INPUT inputStatement 
                {   }

inputStatement: IDENTIFIER TERMINATOR 
                { 
                    checkIfVariableIsIdentifier($1); 
                }   
                | IDENTIFIER SEMICOLON inputStatement 
                { 
                    checkIfVariableIsIdentifier($1);
                }

move:           MOVE INTEGER TO IDENTIFIER TERMINATOR 
                { 
                    moveIntegerToVariable($2, $4); 
                }   
                | MOVE IDENTIFIER TO IDENTIFIER TERMINATOR 
                { 
                    moveIdentifierToVariable($2, $4); 
                }

add:            ADD INTEGER TO IDENTIFIER TERMINATOR 
                { 
                    moveIntegerToVariable($2, $4); 
                }   
                | ADD IDENTIFIER TO IDENTIFIER TERMINATOR 
                { 
                    moveIdentifierToVariable($2, $4); 
                }

end:            END TERMINATOR 
                { 
                    exit(EXIT_SUCCESS); 
                }

%%


int main(void)
{
   int ntoken, vtoken;
   ntoken = 1;
   while(ntoken){
       ntoken = yylex();
   }
   return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error (L%d): %s\n", yylineno, s);
}

void addVariable(int size, char *name) {
    // function that adds variable to our list of identifiers
    insertNullIntoEndOfString(name);
    if (!isIdentifier(name)) {
        strcpy(identifiers[variableCounter], name);
        sizes[variableCounter] = size;
        variableCounter++;
    } else {
        printf("Warning (L%d): Identifier %s already created.\n", yylineno, name);
    }
}

void insertNullIntoEndOfString(char *variable) {
    // function that takes terminators in our language and replaces with 0.
    if (variable[strlen(variable)-1] == '.') {
        variable[strlen(variable)-1] = 0;
    }
}

int isIdentifier(char *variable) {
    // run through list of indentifier and see if our new variable has already been added.
    if (strstr(variable, ";") != NULL) {
        formatVariable(variable);
    }
    for (int i = 0; i < variableCounter; i++) {
        if (strcmp(variable, identifiers[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void formatVariable(char *variable) {
    // function that replaces any semi colons with a c terminator
    for (int i = 0; i < strlen(variable); i++) {
        if (variable[i] == ';' || variable[i] == ' ') {
            variable[i] = '\0';
            break;
        }
    }
}

void checkIfVariableIsIdentifier(char *var) {
    insertNullIntoEndOfString(var);
    if (!isIdentifier(var)) {
        printf("Warning (L%d): Identifier %s not initialised.\n", 
                yylineno, var
            );
    }
}


void moveIntegerToVariable(int num, char *var) {
    insertNullIntoEndOfString(var);
    int size = getIdentifierSize(var);
    // check that there is indeed a intendifier by this name
    if (size > -1) {
        int inputDigits = floor(log10(abs(num))) + 1;
        // check integer will fit in var
        if (inputDigits > size) {
            printf("Warning (L%d): Integer is too large. Expected %d digits or less, is %d.\n", 
                    yylineno, size, inputDigits
                );
        }
    } else {
        printf("Warning (L%d): Integer cannot be assigned. Identifier %s not initialised.\n", 
                yylineno, var
            );
    }
}


void moveIdentifierToVariable(char *firstVariable, char *secondVariable) {
    formatVariable(firstVariable);
    insertNullIntoEndOfString(secondVariable);
    // checking that both these variables are actually identifiers
    if (isIdentifier(firstVariable)) {
            if (isIdentifier(secondVariable)) {
                // getting Identifier sizes now so we can compare differences
                int firstVariableSize = getIdentifierSize(firstVariable);
                int secondVariableSize = getIdentifierSize(secondVariable);
                if (firstVariableSize > secondVariableSize) {
                    printf("Warning (L%d): Moving %s (%d digits) to %s (%d digits).\n", 
                            yylineno, firstVariable, firstVariableSize, secondVariable, secondVariableSize
                        );
                }
        } else {
            printf("Warning (L%d): Identifier %s not initialised.\n", 
                    yylineno, secondVariable
                );
        }
    } else {
        printf("Warning (L%d): Identifier %s not initialised.\n", 
                yylineno, firstVariable
            );
    }
}


int getIdentifierSize(char *var) {
    // find the size of the identifier provided
    for (int i = 0; i < varCounter; i++) {
        if (strcmp(var, identifiers[i]) == 0) {
            return sizes[i];
        }
    }
    return -1;
}
