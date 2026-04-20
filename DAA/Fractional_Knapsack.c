/*🎯 Aim
To write a C program to implement the Fractional Knapsack Algorithm using a greedy approach to maximize profit based on profit per unit weight.*/
//program//
#include<stdio.h>

// structure to store item details
struct Item
{
    int weight;   // weight of item
    int profit;   // profit of item
    float ppw;    // profit per weight
};

// function to sort items in descending order of profit/weight
void sort(struct Item items[], int n)
{
    struct Item temp;

    // bubble sort based on ppw
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (items[j].ppw < items[j + 1].ppw)
            {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, capacity;

    printf("enter number of items :");
    scanf("%d", &n);

    printf("enter the capacity :");
    scanf("%d", &capacity);

    printf("enter weight and profit of items :");

    struct Item items[n]; // array of items

    // input items
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &items[i].weight, &items[i].profit);

        // calculate profit per weight
        items[i].ppw = (float)items[i].profit / items[i].weight;
    }

    // sort items by decreasing ppw
    sort(items, n);

    float totalprofit = 0; // store final profit

    // apply greedy selection
    for (int i = 0; i < n; i++)
    {
        if (items[i].weight <= capacity)
        {
            // take full item
            capacity -= items[i].weight;
            totalprofit += items[i].profit;
        }
        else
        {
            // take fractional part
            totalprofit += items[i].ppw * capacity;
            break;
        }
    }

    // display result
    printf("total profit = %.2f", totalprofit);

    return 0; // end program
}
