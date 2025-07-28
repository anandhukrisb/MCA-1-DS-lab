#include <stdio.h>

int main() {
    char str[100];
    int length = 0;

    // Read the string
    printf("Enter a string: ");
    scanf("%s", str);  // Reads a word (no spaces)

    // Find length of string
    while(str[length] != '\0') {
        length++;
    }

    // Reverse in-place using two-index technique
    for(int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }

    // Print reversed string
    printf("Reversed string (in-place): %s\n", str);

    return 0;
}
