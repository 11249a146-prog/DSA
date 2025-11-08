🎯 Aim:
 To find the position of a given number in a sorted list using the Binary Search method efficiently.

CODE:
 #include <stdio.h>
int binary_search(int arr[], int size, int term) {
    int left = 0;
    int right = size - 1;
    
 // Repeat until the search space is exhausted
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if the term is found at mid
        if (arr[mid] == term)
            return mid; 
        // If the term is greater, ignore the left half
        else if (arr[mid] < term)
            left = mid + 1;
        // If the term is smaller, ignore the right half
        else
            right = mid - 1;
    }
    // Return -1 if the term is not found
    return -1; 
}

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

    // Call binary search function
    int result = binary_search(arr, size, term);
    
    // Display result
    if (result != -1)
        printf("Found at index %d\n", result);
    else
        printf("Not found\n");

    return 0;
}
