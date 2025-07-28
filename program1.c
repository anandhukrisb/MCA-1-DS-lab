
/* 
Q1) Write programs to demonstrate the use of storage classes 
    (local variable, global variable, static variable, register variable) in C.   
*/

#include <stdio.h>

// This variable is available to all functions in the same file.
int globalVariable = 2;


int localFunc() {

    // This variable is only limited to this function or block. 
    // Created when the function is called, destroyed when it exits.

    int localVariable = 1;

    return localVariable;
}

int staticFunc() {
    static int staticVariable = 2;
    staticVariable++;
    return staticVariable;
}

int main() {

    printf("This is a local variable: %d\n", localFunc());
    printf("This is a global variable: %d\n", globalVariable);
    printf("This is a static variable: %d\n", staticFunc());

    // When the function called second time the static variable
    // retains its value between function calls.
    printf("This is a static variable second time: %d\n", staticFunc());


    // A variable declared with the keyword register 
    // to suggest storing it in a CPU register for faster access.
    register int registerVariable = 4;
    
    printf("This is a register variable: %d\n", registerVariable);

    return 0;
}