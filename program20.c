// Evaluate an infix expression using stack 
// input:2+3*4
// output: 14

#include <stdio.h>
#include <ctype.h>

#define MAX 100
char stack[MAX];   // Stack implementation using array
int top = -1;      // Top pointer initialized to -1

// Function to push an element into the stack
void push(char c) {
    if (top == MAX - 1) {   // Check for stack overflow
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;  // Increment top and insert element
}
// Function to pop an element from the stack
char pop() {
    if (top == -1) {   // Check for stack underflow
        printf("Stack Underflow\n");
        return -1;     // Return -1 as error indicator
    }
    return stack[top--];  // Return top element and decrement top
}
// Function to return the top element of the stack without popping
char peek() {
    if (top == -1) {
        return -1;     // Return -1 if stack is empty
    }
    return stack[top];
}
// Function to check if character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
// Function to return precedence of operators
int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;   // Lowest precedence
        case '*':
        case '/':
            return 2;   // Medium precedence
        case '^':
            return 3;   // Highest precedence
        default:
            return -1;  // Not an operator
    }
}
// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char c;
    while ((c = infix[i++]) != '\0') {   // Read characters one by one
        // If operand (letters/numbers), add to postfix directly
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        //
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop();  // Pop the '(' from stack
        }
        // If operator, pop from stack to postfix until top has less precedence than c
        else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }
    // Pop all remaining operators from stack
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';  // Null-terminate the postfix expression
}
// Function to evaluate postfix expression
int evaluatePostfix(char* postfix) {
    int i = 0;
    char c;
    int val1, val2, result;
    while ((c = postfix[i++]) != '\0') {
        // If operand, push to stack
        if (isdigit(c)) {
            push(c - '0');  // Convert char to int and push
        }
        // If operator, pop two elements, apply operator and push result
        else if (isOperator(c)) {
            val2 = pop();
            val1 = pop();
            switch (c) {
                case '+':
                    result = val1 + val2;
                    break;
                case '-':
                    result = val1 - val2;
                    break;
                case '*':
                    result = val1 * val2;
                    break;
                case '/':
                    result = val1 / val2;
                    break;
                case '^': {
                    result = 1;
                    for (int k = 0; k < val2; k++) {
                        result *= val1;
                    }
                    break;
                }
            }
            push(result);  // Push the result back to stack
        }
    }
    return pop();  // Final result is the only element left in stack
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    int result = evaluatePostfix(postfix);
    printf("Evaluated Result: %d\n", result);
    return 0;
}


