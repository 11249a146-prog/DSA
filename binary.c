🧭 Aim:
  To write a C program that performs Binary Search on a sorted array to find the position of a given element.
⚙️ Algorithm:
   1.Input the size and sorted elements of the array.
   2.Input the element to search (term).
   3.Initialize left = 0, right = size - 1.
   4.While left <= right:
   Compute mid = left + (right - left) / 2.
   If arr[mid] == term, return mid.
   If arr[mid] < term, set left = mid + 1.
   Else set right = mid - 1.
   5.If not found, return -1.    
code:
#include <stdio.h>
// Function to perform Binary Search
int binary_search(int arr[], int size, int term) {
    int left = 0;               // Start index
    int right = size - 1;       // End index
// Continue searching while left index is less than or equal to right
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Find middle index safely
     if (arr[mid] == term)                 // If element found
            return mid;                       // Return its index
        else if (arr[mid] < term)             // If element is in right half
            left = mid + 1;
        else                                  // If element is in left half
            right = mid - 1;
    }
    return -1;                                // Element not found
}
int main() {
    int size, term;
    printf("Enter size of array: ");          
    scanf("%d", &size);
    int arr[size];                            // Declare array
    printf("Enter %d sorted numbers:\n", size);
    for (int i = 0; i < size; i++) {          // Input sorted numbers
        scanf("%d", &arr[i]);
    }
     printf("Enter number to search: ");       // Input search element
    scanf("%d", &term);

    int result = binary_search(arr, size, term);  // Call search function

    if (result != -1)                         
        printf("Found at index %d\n", result);
    else                                      
        printf("Not found\n");

    return 0;                                

