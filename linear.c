#include <stdio.h>

int linear_search(int arr[], int size, int term) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == term)
            return i; 
    }
    return -1; 
}

int main() {
    int size, term;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d numbers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number to search: ");
    scanf("%d", &term);

    int result = linear_search(arr, size, term);
    if (result != -1)
        printf("Found at index %d\n", result);
    else
        printf("Not found\n");

    return 0;
}