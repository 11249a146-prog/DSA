/*🎯 Aim
To write a C program to generate the Fibonacci Series up to n terms and display the nth term.*/
//program//
#include <stdio.h>

int main() 
{ 
    int n; 
    int a = 0, b = 1, c; // initialize first two Fibonacci numbers

    printf("Enter the number of terms (n): "); 

    // check for valid input (positive integer)
    if (scanf("%d", &n) != 1 || n <= 0) 
    { 
        printf("Invalid input. Please enter a positive integer.\n"); 
        return 0; // exit if invalid input
    } 

    printf("Fibonacci Series: "); 

    // print first term if n >= 1
    if (n >= 1) 
        printf("%d ", a); 

    // print second term if n >= 2
    if (n >= 2) 
        printf("%d ", b);  // fixed missing semicolon

    // generate remaining Fibonacci terms
    for (int i = 3; i <= n; i++) 
    { 
        c = a + b;        // compute next term
        printf("%d ", c); // print current term

        a = b;            // update a to previous b
        b = c;            // update b to current term
    }         

    // display the nth Fibonacci term
    if (n == 1) 
        printf("\nFibonacci term %d = %d\n", n, a); 
    else 
        printf("\nFibonacci term %d = %d\n", n, b); 

    return 0; // end of program
}
