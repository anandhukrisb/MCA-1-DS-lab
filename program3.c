#include <stdio.h>

// Function to read elements into array
void insert(int a[], int *n) {
    int i;
    printf("Enter number of elements: ");
    scanf("%d", n);
    printf("Enter %d elements: ", *n);
    for(i = 0; i < *n; i++) {
        scanf("%d", &a[i]);
    }
}

// Function to display array
void display(int a[], int n) {
    int i;
    printf("Array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Function to search for an element
void search(int a[], int n) {
    int key, i, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &key);
    for(i = 0; i < n; i++) {
        if(a[i] == key) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if(!found)
        printf("Element not found.\n");
}

// Function to delete an element
void delete(int a[], int *n) {
    int key, i, j, found = 0;
    printf("Enter element to delete: ");
    scanf("%d", &key);
    for(i = 0; i < *n; i++) {
        if(a[i] == key) {
            for(j = i; j < *n - 1; j++) {
                a[j] = a[j + 1];
            }
            (*n)--;
            found = 1;
            printf("Element deleted.\n");
            break;
        }
    }
    if(!found)
        printf("Element not found.\n");
}

// Function to sort the array in ascending order
void sort(int a[], int n) {
    int i, j, temp;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("Array sorted in ascending order.\n");
}

int main() {
    int arr[100], n = 0, choice;

    while(1) {
        printf("\nMenu:\n");
        printf("1. Insert Elements\n");
        printf("2. Display Elements\n");
        printf("3. Search Element\n");
        printf("4. Delete Element\n");
        printf("5. Sort Elements\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: insert(arr, &n); break;
            case 2: display(arr, n); break;
            case 3: search(arr, n); break;
            case 4: delete(arr, &n); break;
            case 5: sort(arr, n); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}
