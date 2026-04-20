/*🎯 Aim
To write a C program to implement the First Fit Algorithm, where each item is placed in the first available bin that can accommodate it.*/
//program//

#include <stdio.h>

// Function to implement First Fit algorithm
void firstFit(int items[], int n, int capacity) 
{ 
    int bin[n];        // stores remaining capacity of bins
    int binCount = 0;  // number of bins used

    // initialize bins with full capacity
    for (int i = 0; i < n; i++) 
        bin[i] = capacity; 

    // loop through each item
    for (int i = 0; i < n; i++) 
    {
        int placed = 0; // flag to check if item is placed

        // check each existing bin
        for (int j = 0; j < binCount; j++) 
        { 
            if (bin[j] >= items[i]) // if item fits
            { 
                bin[j] -= items[i]; // reduce space
                printf("Item %d placed in Bin %d\n", items[i], j + 1);     
                placed = 1;         // mark as placed
                break;              // stop checking further bins
            }  
        }     

        // if item not placed in any bin
        if (!placed) 
        { 
            bin[binCount] -= items[i]; // create new bin
            printf("Item %d placed in Bin %d\n", items[i], binCount + 1); 
            binCount++; // increase bin count
        } 
    } 

    // display total bins used
    printf("Total bins used = %d\n", binCount);
}  

int main() 
{ 
    int n, capacity; 

    printf("Enter number of items: "); 
    scanf("%d", &n);  

    printf("Enter bin capacity: "); 
    scanf("%d", &capacity); 

    int items[n];  // array to store item sizes

    printf("Enter item sizes:\n"); 

    // input items with validation
    for (int i = 0; i < n; i++) 
    { 
        int itemSize; 

        printf("Item %d: ", i + 1); 
        scanf("%d", &itemSize); 
  
        if (itemSize <= capacity) 
        { 
            items[i] = itemSize; 
        } 
        else 
        {      
            // FIXED: removed '1' and completed printf properly
            printf("Item size exceeds bin capacity. Please enter a valid size.\n"); 
            i--; // retry input
        } 
    } 

    firstFit(items, n, capacity); // function call

    return 0; // end program
}
