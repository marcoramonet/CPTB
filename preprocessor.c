/**
 * The preprocessor is a stage in the compiler which checks for definitions of tokens 
    * and replaces their instances for their definitions
 * We should think of preprocessor directives as operations on the current working file, not on te working code.
*/
/*The #define directive replaces all instances of __MY_DEBUG__ with the value of 0*/
#define __IS_DEBUG__ 0
 
    /* When we run the compiler with the -DDEBUG flag, the macro DEBUG is defined. 
     * Therefore the #ifdef evaluates to true, executing the following lines */
#ifdef DEBUG
    // The #undef directive erases the definition of __IS_DEBUG__ 
    #undef __IS_DEBUG__ 
    #define __IS_DEBUG__ 1
#endif

#if __IS_DEBUG__
    #define __MAGIC__ 1
#else
    #define __MAGIC__ 0
#endif

/**
 * We can check if a macro is NOT defined.
 * This will evaluate to false, therefore __SOME_MACRO__ will be defined as "Some macro was not defined"
*/
#ifndef __SOME_MACRO__
    #define __SOME_MACRO__ "Some macro was defined"
#elif 1
    #define __SOME_MACRO__ "Some macro was not defined"
#endif

/**
 * We can also define a macro similar to a function (function-like).
 * A function-like macro is just like a macro, in that it gets replaced by its definition, 
    *  but takes an argument,and the instances of the argument in the definition will be replaced with
    *  whatever we pass to the macro as argument.
 * 
 * The #define directive allows us to define a macro, but this macro can only be defined in a single line. 
 * Macro Continuation Operator (\): 
 * * Lets us define a macro beyond a single line.
 *  */
#define PRINT_VAR_VAL(val)\
    printf("The value of this variable is %d\n", val);
/*
 *  Stringize Operator (#):
 *  * Takes the tokens given in the macro and converts them into string constants. 
    * This operator may be used only in a macro having a specified argument or parameter list.
*/
#define PRINT_STRINGIZED(msg) \
    printf(#msg"\n");

#define PRINT_VAR_NAME(var)\
    printf("The name of this variable is "#var"\n");

#define STRINGIFY(x)\
    #x

/**
 * Token Pasting Operator (##):
    * The token pasting operator allows for two tokens to be joined together.
    * Only usable in a macro definition
*/

/**Append a dot to a token*/
#define APPEND_DOT(a)\
    a##.

/**Concatenate two tokens.*/
#define TOKCAT(a, b)\
    a##b
/**
 * Parameterized Macros: 
    * As shown before, Macros can have parameters, similar to functions
*/
#define SQUARE(x) (x * x)

/**
 * defined() operator:
    * Takes a macro as an argument, and checks whether the macro has been defined.
    * Similar (if not equivalent) to #ifdef
*/
#if defined (SQUARE)
    #define SQR_DEF 1
#endif

// The #include directive tells the preprocessor to substitute that line of code by the header file, thus defining the methods defined in the header file.
#include <stdio.h>

int main()
{
    
    /**
     * NOTE: If we compile with the flag -E we can see the resulting code with the preprocessor's replacements. 
     * I.O.W. the -E flag tells the compiler to stop after the preprocessing stage
     * 
     * 
     * This gets replaced in the preprocessor time to printf();
     * NOTE: the macros already write a semicolon (;) so we don't have to write one.
    */

    int my_num = 10;

    PRINT_VAR_VAL(my_num) // Gets replaced by: <printf("The value of this variable is %d", my_num);>
    PRINT_STRINGIZED("Hello world")
    PRINT_STRINGIZED(some_token) // Gets replaced by <printf("some_token""\n");>
    PRINT_VAR_NAME(my_num)

    TOKCAT(my_, num) = 20; //Here, <TOKCAT(my_, num)> gets replaced by <my_num>
    printf("my_num: %d\n", TOKCAT(my_, num));

    // Let's say I want to declare a set of variables with the same prefix:
    char TOKCAT(my_, char) = 'J';
    double TOKCAT(my_, double) = 2.5;
    printf("my_char: %c\n", my_char);
    printf("my_double: %f\n", my_double);

    printf("STRINGIFY(my_char): "STRINGIFY(my_char)"\n");
    if (SQR_DEF) {
        printf("SQUARE(my_num): %d\n", SQUARE(my_num));
    }
    


    printf("\n");

    /**
     * Some macros are already defined by the ANSI standard, some of them as strings and some of them as ints.
    */
    printf("Some Macros are defined by the ANSI standard:\n");
    printf("Are we debugging?: %d\n", __IS_DEBUG__);
    printf("Date: %s\n", __DATE__);
    printf("Time: %s\n", __TIME__);
    printf("File: %s\n", __FILE__);
    printf("Line: %d\n", __LINE__);
    printf("Compliant with ANSI?: %d\n", __STDC__); // __STDC__ has a value of 1 if the compiler is compliant with the ANSI standard.
    return 0;
}


/**
 * Bibliography:
    * C - Preprocessors: https://www.tutorialspoint.com/cprogramming/c_preprocessors.html
    * *  -> Token-Pasting Operator ## | C Programming Tutorial:  https://www.youtube.com/watch?v=Cl2rinXQWgs
 * 
*/