#include <stdio.h>

int a[4], pos = -1;

void insert(int e) {
    if(pos + 1 == 4) {
        printf("The array is Full!!");
    }
    else {
        a[++pos] =e;
    }
}

void search(int e) {
    
    int size = sizeof(a) / sizeof(a[0]);
    int isFound = 0;
    int searchPosition;

    for(int i = 0; i < size; i++) {
        if(a[i] == e) {
            isFound = 1;
            searchPosition = i + 1;
            break;
        }
    }
    if(isFound) {
        printf("\nElement found at position %d\n", searchPosition);
    }
    else {
        printf("Element not found!!");
    }
}

void delete(int p) {
    int size = sizeof(a) / sizeof(a[0]);
    for(int i = p; i < size; i++) {
        a[i] = a[i + 1];
        size--;
    }
    pos--;
    printf("Deleted the element at position %d\n", p);

    for(int i = 0; i <= size; i++) {
        printf("%d ", a[i]);
    }
}

void sort() {
    int temp;

    printf("Original Array: ");
    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        printf("%d ", a[i]);
    }

    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        for(int j = 0; j < (sizeof(a) / sizeof(a[0])) - i - 1; j++) {
            if(a[j + 1] < a[j]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("Sorted Array:");
    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        printf("%d ", a[i]);
    }
}

void display() {
    printf("Array: ");
    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        printf("%d ", a[i]);
    }
}

int menu() {
    int ch;

    printf("\n1) Insert\n2) Search\n3) Delete at a posotion\n4) Sort\n5) Display 6) Exit\n Enter your choice: ");
    scanf("%d", &ch);

    return ch;
}

void processArray() {

    int e;
    
    for(int ch = menu(); ch != 6; ch = menu()) {
        
        switch (ch) {
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
            printf("Enter the postition to delete: ");
            scanf("%d", &e);
            delete(e);
            break;
        case 4:
            sort();
        case 5:
            display();
        default:
            break;
        }
    }
    printf("Exiting...");
}

int main() {

    processArray();

    return 0;
}