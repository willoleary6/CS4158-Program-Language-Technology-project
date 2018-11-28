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
int isVariableAlreadyDeclared(char *variable);
void formatVariable(char *variable);
void checkIfVariableisInitialised(char *var);
void moveIntegerToVariable(int num, char *var);
int getVariableSize(char *var);
void assignVariableToAnother(char *firstVariable, char *secondVariable);

int hasErrors = 0;
char variables[NUM_VARIABLES][32];
int variableCounter = 0;
int sizes[NUM_VARIABLES];

%}

%union {
        char *id; 
        int size;
    }
%start start
%token <id> VARIABLE TEXT
%token <size> INTEGER NUMSIZE
%token BEGINING BODY END MOVE TO ADD INPUT PRINT SEMICOLON TERMINATOR INVALID

%%

start:          BEGINING TERMINATOR declarations 
                {   }

declarations:   statement declarations 
                    {   }   
                        | body 
                            {   }

statement:    NUMSIZE VARIABLE TERMINATOR 
                { 
                    addVariable($1, $2); 
                }

body:           BODY TERMINATOR code 
                    {   }

code:           lineOfCode code 
                    {   }   
                        | end 
                            {   }

lineOfCode:     input | print | move | add 
                    {   }

input:          INPUT inputStatement 
                    {   }

inputStatement: VARIABLE TERMINATOR 
                    { 
                        checkIfVariableisInitialised($1); 
                    }   
                        | VARIABLE SEMICOLON inputStatement 
                            { 
                                checkIfVariableisInitialised($1);
                            }

print:          PRINT printStatement 
                    {   }

printStatement: TEXT SEMICOLON printStatement 
                    {   } 
                        | TEXT TERMINATOR 
                            {   }
                                | VARIABLE TERMINATOR 
                                    { 
                                        checkIfVariableisInitialised($1); 
                                    }     
                                    | VARIABLE SEMICOLON printStatement 
                                        { 
                                            checkIfVariableisInitialised($1); 
                                        }
                                

move:           MOVE INTEGER TO VARIABLE TERMINATOR 
                    { 
                        moveIntegerToVariable($2, $4); 
                    }   
                        | MOVE VARIABLE TO VARIABLE TERMINATOR 
                            { 
                                assignVariableToAnother($2, $4); 
                            }

add:            ADD INTEGER TO VARIABLE TERMINATOR 
                    { 
                        moveIntegerToVariable($2, $4); 
                    }   
                        | ADD VARIABLE TO VARIABLE TERMINATOR 
                            { 
                                assignVariableToAnother($2, $4); 
                            }

end:            END TERMINATOR 
                    { 
                        exit(EXIT_SUCCESS); 
                    }

%%


int main() {
    yyparse();
    if (hasErrors == 0) {
        printf("Program conforms perfectly.\n");
    }
    return hasErrors;
}

void yyerror(const char* s) {
    printf("%s on line %d\n", s, yylineno);
    hasErrors = 1;
}

void addVariable(int size, char *name) {
    // function that adds variable to our list of variables
    insertNullIntoEndOfString(name);
    if (!isVariableAlreadyDeclared(name)) {
        strcpy(variables[variableCounter], name);
        sizes[variableCounter] = size;
        variableCounter++;
    } else {
        printf("Warning on line: (L%d): Variable %s already in use.\n"
                , yylineno, name
            );
    }
}

void insertNullIntoEndOfString(char *variable) {
    // function that takes terminators in our language and replaces with 0.
    if (variable[strlen(variable)-1] == '.') {
        variable[strlen(variable)-1] = 0;
    }
}

int isVariableAlreadyDeclared(char *variable) {
    // run through list of indentifier and see if our new variable has already been added.
    if (strstr(variable, ";") != NULL) {
        formatVariable(variable);
    }
    for (int i = 0; i < variableCounter; i++) {
        if (strcmp(variable, variables[i]) == 0) {
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

void checkIfVariableisInitialised(char *var) {
    insertNullIntoEndOfString(var);
    if (!isVariableAlreadyDeclared(var)) {
        printf("Warning (L%d): Variable %s not initialised.\n", 
                yylineno, var
            );
    }
}


void moveIntegerToVariable(int num, char *var) {
    insertNullIntoEndOfString(var);
    int size = getVariableSize(var);
    // check that there is indeed a intendifier by this name
    if (size > -1) {
        int inputDigits = floor(log10(abs(num))) + 1;
        // check integer will fit in var
        if (inputDigits > size) {
            printf("Warning (L%d): Integer is too big. Expected %d digits or less, is %d.\n", 
                    yylineno, size, inputDigits
                );
        }
    } else {
        printf("Warning (L%d): Integer cannot be assigned. Variable %s not initialised.\n", 
                yylineno, var
            );
    }
}


void assignVariableToAnother(char *firstVariable, char *secondVariable) {
    formatVariable(firstVariable);
    insertNullIntoEndOfString(secondVariable);
    // checking that both these variables are actually variables
    if (isVariableAlreadyDeclared(firstVariable)) {
            if (isVariableAlreadyDeclared(secondVariable)) {
                // getting Identifier sizes now so we can compare differences
                int firstVariableSize = getVariableSize(firstVariable);
                int secondVariableSize = getVariableSize(secondVariable);
                if (firstVariableSize > secondVariableSize) {
                    printf("Warning (L%d): Moving %s (%d digits) to %s (%d digits).\n", 
                            yylineno, firstVariable, firstVariableSize, 
                            secondVariable, secondVariableSize
                        );
                }
        } else {
            printf("Warning (L%d): Variable %s not initialised.\n", 
                    yylineno, secondVariable
                );
        }
    } else {
        printf("Warning (L%d): Variable %s not initialised.\n", 
                yylineno, firstVariable
            );
    }
}


int getVariableSize(char *var) {
    // find the size of the identifier provided
    for (int i = 0; i < variableCounter; i++) {
        if (strcmp(var, variables[i]) == 0) {
            return sizes[i];
        }
    }
    return -1;
}
