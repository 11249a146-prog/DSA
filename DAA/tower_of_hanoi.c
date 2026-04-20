/*🎯 Aim
To write a C program to solve the Tower of Hanoi problem using recursion.*/
//program//
#include<stdio.h>

// recursive function for Tower of Hanoi
void tower(int n, char S, char D, char T)
{
    // base case: if only one disk
    if(n == 1)
    {
        printf("Move the disk %d from %c to %c\n", n, S, D);
        return;
    }

    // move n-1 disks from Source to Temporary
    tower(n - 1, S, T, D);   // FIXED: removed quotes (use variables)

    // move nth disk from Source to Destination
    printf("Move disk %d from %c to %c\n", n, S, D);

    // move n-1 disks from Temporary to Destination
    tower(n - 1, T, D, S);
}

int main()
{
    int disk_count;

    printf("Enter the no of Disk: ");
    scanf("%d", &disk_count);

    printf("\nRequired moves:\n");

    // function call
    tower(disk_count, 'S', 'D', 'T');

    return 0; // end program
}
