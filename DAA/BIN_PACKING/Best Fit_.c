// AIM :To write a C program to implement the Best Fit Algorithm for bin packing, where each item is placed in the bin that leaves the least remaining space after allocation.//

#include <stdio.h>

// Function for Best Fit allocation
void bestFit(int items[], int n, int capacity)
{
    printf("\nBest Fit Algorithm\n");

    int bin[n];        // stores remaining space in each bin
    int binCount = 0;  // number of bins used

    // initialize all bins with full capacity
    for (int i = 0; i < n; i++)
        bin[i] = capacity;

    // loop through each item
    for (int i = 0; i < n; i++)
    {
        int bestIndex = -1;          // index of best bin
        int minSpace = capacity + 1; // track minimum leftover space

        // check all existing bins
        for (int j = 0; j < binCount; j++)
        {
            // check if item fits and leaves minimum space
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace)
            {
                bestIndex = j;                // update best bin
                minSpace = bin[j] - items[i];
            }
        }

        // if suitable bin found
        if (bestIndex != -1)
        {
            bin[bestIndex] -= items[i]; // reduce space in that bin

            printf("Item %d (weight: %d) placed in Bin %d\n",
                   i + 1, items[i], bestIndex + 1);
        }
        else
        {
            // create new bin
            bin[binCount] -= items[i];
            binCount++; // increase bin count

            printf("Item %d (weight: %d) placed in Bin %d\n",
                   i + 1, items[i], binCount);
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

    int items[n]; // array to store item sizes

    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    printf("Enter item sizes:\n");

    // input items with validation
    for (int i = 0; i < n; i++)
    {
        int itemSize;

        printf("Item %d: ", i + 1);
        scanf("%d", &itemSize);

        // check if item is valid
        if (itemSize <= capacity)
        {
            items[i] = itemSize;
        }
        else
        {
            printf("Item size exceeds bin capacity. Enter again.\n");
            i--; // retry same item
        }
    }

    bestFit(items, n, capacity); // function call

    return 0; // end program
}
