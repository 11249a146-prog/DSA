#include <stdio.h>

int binary_search(int arr[], int size, int term) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == term)
            return mid; 
        else if (arr[mid] < term)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; 
int main() {
    int size, term;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d sorted numbers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number to search: ");
    scanf("%d", &term);

    int result = binary_search(arr, size, term);
    if (result != -1)
        printf("Found at index %d\n", result);
    else
        printf("Not found\n");

    return 0;
}