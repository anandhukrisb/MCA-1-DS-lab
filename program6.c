#include <stdio.h>

// Function to read array elements
void read(int arr[], int size) {
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Recursive function to display array elements in same order
void displayRecursive(int arr[], int index, int size) {
    if (index >= size) {
        return; // Base case: stop when index reaches size
    }

    printf("%d ", arr[index]);          // Print current element
    displayRecursive(arr, index + 1, size); // Recursive call for next index
}

int main() {
    int arr[100], size;

    // Input size of array
    printf("Enter size of array: ");
    scanf("%d", &size);

    // Read elements
    read(arr, size);

    // Display using recursion
    printf("Array elements (recursively):\n");
    displayRecursive(arr, 0, size);

    return 0;
}
