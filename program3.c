
/* 
Q2) Use a menu-driven program to insert, search, delete and sort elements 
    in an array using functions (use global variables)   
*/

#include <stdio.h>

// This is a function to insert elements into the array from the back.
// e is the parameter for element.
void insert(int a[], int pos, int e) {
    if(pos + 1 == 4) {
        printf("The array is Full!!");
    }
    else {
        a[++pos] =e;
    }
}

// This search function is for searching an element in the array and in returns it prints
// the position.
void search(int a[], int pos, int e) {
    
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

// This delete function deletes an element from the array from a specific position.
void delete(int a[], int pos, int p) {
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

// This sort function sorts element in ascending order when called.
void sort(int a[]) {
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

// This display function displays all element in an array when called.
void display(int a[]) {
    printf("Array: ");
    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        printf("%d ", a[i]);
    }
}


// This function provides the choices and lets the user choose their choice when called.
int menu() {
    int ch;

    printf("\n1) Insert\n2) Search\n3) Delete at a posotion\n4) Sort\n5) Display \n6) Exit\n Enter your choice: ");
    scanf("%d", &ch);

    return ch;
}

// This function provide the corresponding functions when the user select their choices from the 
// menu() function.
void processArray() {

    // a[4] and pos are local variable and only accessed by other functions when  
    // passed as arguments.
    int a[4], pos = -1;

    int e;
    
    for(int ch = menu(); ch != 6; ch = menu()) {
        
        switch (ch) {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &e);
            insert(a, pos, e);
            break;
        case 2:
            printf("Enter the element to search: ");
            scanf("%d", &e);
            search(a, pos, e);
            break;
        case 3:
            printf("Enter the postition to delete: ");
            scanf("%d", &e);
            delete(a, pos, e);
            break;
        case 4:
            sort(a);
            break;
        case 5:
            display(a);
            break;
        default:
            printf("Enter a valid function!");
            break;
        }
    }
    printf("Exiting...");
}

// The main function only calls processArray function and handle these array operations.
int main() {
    processArray();

    return 0;
}