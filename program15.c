#include <stdio.h>
#include <string.h>

int main() {
    char str[100][100];  // Array to store up to 100 strings (each max 100 chars)
    int n;

    // Input number of strings
    printf("Enter number of strings: ");
    scanf("%d", &n);

    // Read strings
    printf("Enter %d strings:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%s", str[i]);  // Reads word (not sentence)
    }

    // Sort strings using Bubble Sort logic
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(strcmp(str[i], str[j]) > 0) {
                // Swap strings
                char temp[100];
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    // Display sorted strings
    printf("\nStrings in ascending order:\n");
    for(int i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }

    return 0;
}
