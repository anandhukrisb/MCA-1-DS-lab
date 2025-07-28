#include <stdio.h>

int a[4], pos = -1; // global array and position tracker

// Insert element at the end
void insert(int e) {
    if(pos + 1 == 4) {
        printf("The array is full!!\n");
    } else {
        a[++pos] = e;
        printf("Inserted %d\n", e);
    }
}

// Search for an element in the array
void search(int e) {
    int isFound = 0;
    int searchPosition;

    for(int i = 0; i <= pos; i++) {
        if(a[i] == e) {
            isFound = 1;
            searchPosition = i + 1;
            break;
        }
    }
    if(isFound) {
        printf("Element found at position %d\n", searchPosition);
    } else {
        printf("Element not found!!\n");
    }
}

// Delete element at a given position (1-based)
void deleteElement(int p) {
    if(p < 1 || p > pos + 1) {
        printf("Invalid position!\n");
        return;
    }

    for(int i = p - 1; i < pos; i++) {
        a[i] = a[i + 1];
    }

    pos--;
    printf("Deleted the element at position %d\n", p);
}

// Sort elements in ascending order
void sort() {
    int temp;
    for(int i = 0; i <= pos; i++) {
        for(int j = 0; j < pos - i; j++) {
            if(a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("Array sorted in ascending order.\n");
}

// Display all elements
void display() {
    if(pos == -1) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for(int i = 0; i <= pos; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Show menu and return user choice
int menu() {
    int ch;
    printf("\n1) Insert\n2) Search\n3) Delete at a position\n4) Sort\n5) Display\n6) Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}

// Main logic controller
void processArray() {
    int e;

    while(1) {
        int ch = menu();

        switch(ch) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &e);
                insert(e);
                break;
            case 2:
                printf("Enter the element to search: ");
                scanf("%d", &e);
                search(e);
                break;
            case 3:
                printf("Enter the position to delete (1-based): ");
                scanf("%d", &e);
                deleteElement(e);
                break;
            case 4:
                sort();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                return;
            default:
                printf("Enter a valid choice!\n");
        }
    }
}

// Main function
int main() {
    processArray();
    return 0;
}
