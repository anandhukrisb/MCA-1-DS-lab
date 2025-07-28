#include <stdio.h>

// Function to read array elements
void read(int arr[], int size) {
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Recursive function to display elements in reverse order
void displayReverse(int arr[], int index) {
    if (index < 0) {
        return; // Base case: when index becomes negative, stop
    }

    printf("%d ", arr[index]);          // Print current element
    displayReverse(arr, index - 1);     // Recursive call for previous element
}

int main() {
    int arr[100], size;

    // Input size of array
    printf("Enter size of array: ");
    scanf("%d", &size);

    // Read elements
    read(arr, size);

    // Display using recursion in reverse order
    printf("Array elements in reverse order (recursively):\n");
    displayReverse(arr, size - 1);

    return 0;
}
