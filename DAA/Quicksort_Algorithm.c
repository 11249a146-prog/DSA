//Aim: To develop and implement a randomized Quicksort algorithm that selects pivot elements randomly for sorting data efficiently and improving average-case performance.//
//program//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to swap two numbers */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Partition function */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

/* Randomized Quick Sort */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int randomIndex = low + rand() % (high - low + 1);

        swap(&arr[randomIndex], &arr[high]);   // Random pivot

        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);   // Left side
        quickSort(arr, p + 1, high);  // Right side
    }
}

int main()
{
    int n;

    srand(time(NULL));   // Seed for random numbers

    printf("Enter number of elements: ");

    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input\n");
        return 1;
    }

    int arr[n];

    printf("Enter %d integers: ", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);   // Function call

    printf("\nSorted array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
