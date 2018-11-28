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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
        char *id; 
        int size;
    } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
