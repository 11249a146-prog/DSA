/*🎯 Aim
To write a C program to find the Minimum Spanning Tree using Prim's Algorithm.*/
//program//
#include <stdio.h>
#include <stdlib.h>

#define V 5  // number of vertices

// function to find vertex with minimum key value
int minKey(int key[], int visited[]) 
{ 
    int min = 999999; 
    int min_index = 0; 

    for (int i = 0; i < V; i++) 
    { 
        if (!visited[i] && key[i] < min) 
        { 
            min = key[i]; 
            min_index = i; 
        } 
    } 

    return min_index; 
} 

// function to print MST
void printPrimMST(int parent[], int graph[V][V]) 
{ 
    printf("\nPrim's MST:\n"); 
    printf("Edge \tWeight\n"); 

    int total = 0; 

    for (int i = 1; i < V; i++) 
    { 
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]); 
        total += graph[i][parent[i]]; // calculate total cost
    } 

    printf("Total Cost = %d\n", total); 
} 

// Prim's algorithm function
void primMST(int graph[V][V]) 
{ 
    int parent[V];   // store MST
    int key[V];      // store minimum weight
    int visited[V];  // track visited vertices

    // initialize all keys as infinite and visited as false
    for (int i = 0; i < V; i++) 
    { 
        key[i] = 999999; 
        visited[i] = 0; 
    } 

    key[0] = 0;    // start from vertex 0
    parent[0] = -1; 

    // build MST
    for (int count = 0; count < V - 1; count++) 
    { 
        int u = minKey(key, visited); // pick minimum key vertex
        visited[u] = 1;  

        // update adjacent vertices
        for (int v = 0; v < V; v++) 
        { 
            // FIXED: removed broken text and corrected condition
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
            { 
                parent[v] = u; 
                key[v] = graph[u][v]; 
            } 
        } 
    } 

    printPrimMST(parent, graph); // print result
} 

int main() 
{ 
    // adjacency matrix of graph
    int graph[V][V] = { 
        {0, 2, 3, 0, 0}, 
        {2, 0, 5, 3, 0}, 
        {3, 5, 0, 0, 4}, 
        {0, 3, 0, 0, 2}, 
        {0, 0, 4, 2, 0}
    }; 

    primMST(graph); // function call

    return 0; // end program
}
