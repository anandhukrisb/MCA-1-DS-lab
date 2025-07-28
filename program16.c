#include <stdio.h>
#define MAX 100

char stack[MAX];  // Stack array
int top = -1;     // Top of stack

// Function to push a character onto the stack
void push(char ch) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = ch;
    }
}

// Function to pop a character from the stack
char pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

int main() {
    char str[MAX];
    int i;

    // Read the string
    printf("Enter a string: ");
    scanf("%s", str);  // Reads up to whitespace

    // Push each character onto the stack
    for(i = 0; str[i] != '\0'; i++) {
        push(str[i]);
    }

    // Pop all characters to reverse the string
    printf("Reversed string: ");
    while(top != -1) {
        printf("%c", pop());
    }

    printf("\n");

    return 0;
}
