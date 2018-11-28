/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20170709

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
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

/* prototyping functions*/
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

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 32 "parser.y"
typedef union {
        char *id; 
        int size;
    } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 62 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define VARIABLE 257
#define TEXT 258
#define INTEGER 259
#define NUMSIZE 260
#define BEGINING 261
#define BODY 262
#define END 263
#define MOVE 264
#define TO 265
#define ADD 266
#define INPUT 267
#define PRINT 268
#define SEMICOLON 269
#define TERMINATOR 270
#define INVALID 271
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    3,    4,    4,    5,    5,    5,
    5,    7,   11,   11,    8,   12,   12,   12,   12,    9,
    9,   10,   10,    6,
};
static const YYINT yylen[] = {                            2,
    3,    2,    1,    3,    3,    2,    1,    1,    1,    1,
    1,    2,    2,    3,    2,    3,    2,    2,    3,    5,
    5,    5,    5,    2,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    1,    0,    3,    0,    0,
    2,    4,    0,    0,    0,    0,    0,    5,    0,    7,
    8,    9,   10,   11,   24,    0,    0,    0,    0,    0,
   12,    0,    0,   15,    6,    0,    0,    0,    0,    0,
   13,    0,   18,    0,   17,    0,    0,    0,    0,   14,
   19,   16,   21,   20,   23,   22,
};
static const YYINT yydgoto[] = {                          2,
    6,    7,    8,   18,   19,   20,   21,   22,   23,   24,
   31,   34,
};
static const YYINT yysindex[] = {                      -259,
 -248,    0, -254, -234, -246,    0, -254,    0, -245, -263,
    0,    0, -244, -250, -247, -230, -243,    0, -263,    0,
    0,    0,    0,    0,    0, -237, -236, -235, -233, -253,
    0, -251, -249,    0,    0, -226, -224, -223, -222, -230,
    0, -243,    0, -243,    0, -232, -231, -229, -228,    0,
    0,    0,    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   29,    0,    0,   18,    0,    0,    0,    0,    0,    0,
    3,  -31,
};
#define YYTABLESIZE 43
static const YYINT yytable[] = {                         13,
   14,    1,   15,   16,   17,    4,   26,    5,   27,   28,
   51,   29,   52,   32,   33,   40,   41,   42,   43,   44,
   45,    3,    9,   10,   12,   25,   30,   36,   37,   38,
   46,   39,   47,   48,   49,   11,   35,   53,   54,    0,
   55,   56,   50,
};
static const YYINT yycheck[] = {                        263,
  264,  261,  266,  267,  268,  260,  257,  262,  259,  257,
   42,  259,   44,  257,  258,  269,  270,  269,  270,  269,
  270,  270,  257,  270,  270,  270,  257,  265,  265,  265,
  257,  265,  257,  257,  257,    7,   19,  270,  270,   -1,
  270,  270,   40,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 271
#define YYUNDFTOKEN 286
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"VARIABLE","TEXT","INTEGER",
"NUMSIZE","BEGINING","BODY","END","MOVE","TO","ADD","INPUT","PRINT","SEMICOLON",
"TERMINATOR","INVALID",0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"start : BEGINING TERMINATOR declarations",
"declarations : statement declarations",
"declarations : body",
"statement : NUMSIZE VARIABLE TERMINATOR",
"body : BODY TERMINATOR code",
"code : lineOfCode code",
"code : end",
"lineOfCode : input",
"lineOfCode : print",
"lineOfCode : move",
"lineOfCode : add",
"input : INPUT inputStatement",
"inputStatement : VARIABLE TERMINATOR",
"inputStatement : VARIABLE SEMICOLON inputStatement",
"print : PRINT printStatement",
"printStatement : TEXT SEMICOLON printStatement",
"printStatement : TEXT TERMINATOR",
"printStatement : VARIABLE TERMINATOR",
"printStatement : VARIABLE SEMICOLON printStatement",
"move : MOVE INTEGER TO VARIABLE TERMINATOR",
"move : MOVE VARIABLE TO VARIABLE TERMINATOR",
"add : ADD INTEGER TO VARIABLE TERMINATOR",
"add : ADD VARIABLE TO VARIABLE TERMINATOR",
"end : END TERMINATOR",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 120 "parser.y"


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
#line 379 "y.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 1:
#line 44 "parser.y"
	{   }
break;
case 2:
#line 47 "parser.y"
	{   }
break;
case 3:
#line 49 "parser.y"
	{   }
break;
case 4:
#line 52 "parser.y"
	{ 
                    addVariable(yystack.l_mark[-2].size, yystack.l_mark[-1].id); 
                }
break;
case 5:
#line 57 "parser.y"
	{   }
break;
case 6:
#line 60 "parser.y"
	{   }
break;
case 7:
#line 62 "parser.y"
	{   }
break;
case 11:
#line 65 "parser.y"
	{   }
break;
case 12:
#line 68 "parser.y"
	{   }
break;
case 13:
#line 71 "parser.y"
	{ 
                        checkIfVariableisInitialised(yystack.l_mark[-1].id); 
                    }
break;
case 14:
#line 75 "parser.y"
	{ 
                                checkIfVariableisInitialised(yystack.l_mark[-2].id);
                            }
break;
case 15:
#line 80 "parser.y"
	{   }
break;
case 16:
#line 83 "parser.y"
	{   }
break;
case 17:
#line 85 "parser.y"
	{   }
break;
case 18:
#line 87 "parser.y"
	{ 
                                        checkIfVariableisInitialised(yystack.l_mark[-1].id); 
                                    }
break;
case 19:
#line 91 "parser.y"
	{ 
                                            checkIfVariableisInitialised(yystack.l_mark[-2].id); 
                                        }
break;
case 20:
#line 97 "parser.y"
	{ 
                        moveIntegerToVariable(yystack.l_mark[-3].size, yystack.l_mark[-1].id); 
                    }
break;
case 21:
#line 101 "parser.y"
	{ 
                                assignVariableToAnother(yystack.l_mark[-3].id, yystack.l_mark[-1].id); 
                            }
break;
case 22:
#line 106 "parser.y"
	{ 
                        moveIntegerToVariable(yystack.l_mark[-3].size, yystack.l_mark[-1].id); 
                    }
break;
case 23:
#line 110 "parser.y"
	{ 
                                assignVariableToAnother(yystack.l_mark[-3].id, yystack.l_mark[-1].id); 
                            }
break;
case 24:
#line 115 "parser.y"
	{ 
                        exit(EXIT_SUCCESS); 
                    }
break;
#line 682 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
