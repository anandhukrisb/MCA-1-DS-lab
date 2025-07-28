#include <stdio.h>

// Function to read array elements
void read(int arr[], int size) {
    printf("Enter %d elements:\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to display array elements
void disp(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort array in ascending order using Bubble Sort
void sort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[100], size;

    // Input the size of the array
    printf("Enter size of array: ");
    scanf("%d", &size);

    // Read elements
    read(arr, size);

    // Display before sorting
    printf("Array before sorting:\n");
    disp(arr, size);

    // Sort the array
    sort(arr, size);

    // Display after sorting
    printf("Array after sorting in ascending order:\n");
    disp(arr, size);

    return 0;
}
