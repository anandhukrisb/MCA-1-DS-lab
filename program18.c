// infix to prefix conversion using stack
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
char stack[MAX];   // Stack implementation using array
int top = -1;      // Top pointer initialized to -1
char prefix[MAX];  // Array to store the prefix expression
int pIndex = 0;    // Index for prefix array
char infix[MAX];   // Array to store the infix expression
int i = 0;         // Index for infix array
int j = 0;         // Index for postfix array
char c;           // Current character being processed
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
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix[j++] = c;
        }
        // If '(', push to stack
        else if (c == '(') {
            push(c);
        }
        // If ')', pop and output from the stack until an '(' is encountered
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop();  // Remove '(' from stack
        }
        // If operator, pop from stack to postfix until top has less precedence than c
        else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }
    // Pop all remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';  // Null-terminate the postfix expression
}
// Function to reverse a string
void reverse(char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
// Function to convert infix expression to prefix expression
void infixToPrefix(char* infix, char* prefix) {
    char reversedInfix[MAX];
    char postfix[MAX];
    int i = 0, j = 0;
    // Step 1: Reverse the infix expression
    while (infix[i] != '\0') {
        reversedInfix[i] = infix[i];
        i++;
    }
    reversedInfix[i] = '\0';
    reverse(reversedInfix);
    // Step 2: Replace '(' with ')' and vice versa
    for (i = 0; reversedInfix[i] != '\0'; i++) {
        if (reversedInfix[i] == '(') {
            reversedInfix[i] = ')';
        } else if (reversedInfix[i] == ')') {
            reversedInfix[i] = '(';
        }
    }
    // Step 3: Get postfix of the modified expression
    infixToPostfix(reversedInfix, postfix);
    // Step 4: Reverse the postfix to get prefix
    reverse(postfix);
    // Copy the result to prefix
    for (i = 0; postfix[i] != '\0'; i++) {
        prefix[i] = postfix[i];
    }
    prefix[i] = '\0';  // Null-terminate the prefix expression
}
int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];
    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infixToPrefix(infix, prefix);
    printf("Prefix: %s\n", prefix);
    return 0;
}