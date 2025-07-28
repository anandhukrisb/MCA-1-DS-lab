#include <stdio.h>

// Function to input array elements
void inputArray(int arr[], int size) {
    printf("Enter %d elements:\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to display array elements
void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to search for all occurrences of a target element
void searchOccurrences(int arr[], int size, int target) {
    int found = 0;
    printf("Element %d found at positions: ", target);
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            printf("%d ", i);  // Print the index (position) of occurrence
            found = 1;
        }
    }
    if (!found) {
        printf("Not found.");
    }
    printf("\n");
}

int main() {
    int arr[100], size, target;

    // Ask user for array size
    printf("Enter size of array: ");
    scanf("%d", &size);

    // Input array elements
    inputArray(arr, size);

    // Display the array
    displayArray(arr, size);

    // Ask user for the element to search
    printf("Enter element to search: ");
    scanf("%d", &target);

    // Search and print all occurrences
    searchOccurrences(arr, size, target);

    return 0;
}
