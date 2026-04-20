/*🎯 Aim
To write a C program to find the nth term of the Fibonacci Series using recursion.*/
//program//
#include<stdio.h>

// recursive function to find nth Fibonacci term
int fib(int n) 
{   
    if (n <= 1) 
    { 
        return n; // base case
    }   

    return fib(n - 1) + fib(n - 2); // recursive call
}

int main()  
{ 
    int n, result = 0;  

    // take input from user
    printf("Enter n: ");
    scanf("%d", &n);

    // validate input
    if (n < 0) 
    { 
        printf("Invalid input\n"); 
        return 1; 
    } 

    // compute and display result
    result = fib(n);

    printf("\nNth Fibonacci term = %d\n", result); 

    return 0; // end program
}
