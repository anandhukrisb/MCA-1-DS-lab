#include <stdio.h>

int main() {
    char str[100];
    int length = 0;

    // Read the string
    printf("Enter a string: ");
    scanf("%s", str); // This reads input until space or newline

    // Find the length of the string manually
    while(str[length] != '\0') {
        length++;
    }

    // Print the string in reverse
    printf("Reversed string: ");
    for(int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    printf("\n");

    return 0;
}
