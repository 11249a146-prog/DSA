/*🎯 Aim
To write a C program to find the Minimum Spanning Tree using Kruskal's Algorithm.*/
//program//
#include <stdio.h>

#define V 5  // number of vertices
#define E 6  // number of edges

int parent[V];  // parent array for union-find

// find the leader (root) of a set
int findLeader(int v) 
{ 
    while (parent[v] != v) 
        v = parent[v]; 
    return v; 
} 

// merge two sets
void mergeSets(int u, int v) 
{ 
    int a = findLeader(u); 
    int b = findLeader(v); 
    parent[a] = b; 
} 

// sort edges based on weight (ascending)
void sortEdges(int edges[E][3]) 
{ 
    for (int i = 0; i < E - 1; i++) 
    { 
        for (int j = 0; j < E - i - 1; j++) 
        { 
            if (edges[j][2] > edges[j + 1][2])
            { 
                for (int k = 0; k < 3; k++) 
                { 
                    int temp = edges[j][k]; 
                    edges[j][k] = edges[j + 1][k]; 
                    edges[j + 1][k] = temp; 
                } 
            } 
        } 
    } 
} 

// Kruskal's algorithm
void kruskal(int edges[E][3]) 
{ 
    sortEdges(edges); // sort edges by weight

    // initialize parent array
    for (int i = 0; i < V; i++) 
        parent[i] = i; 

    int count = 0, cost = 0; 

    printf("Selected Edges:\n"); 

    // process edges
    for (int i = 0; i < E; i++) 
    { 
        int u = edges[i][0]; 
        int v = edges[i][1]; 
        int w = edges[i][2]; 

        // stop if MST is complete
        if (count == V - 1) 
            break; 

        // check if edge forms cycle
        if (findLeader(u) != findLeader(v)) 
        { 
            printf("%d -- %d (Weight: %d)\n", u, v, w); 
            mergeSets(u, v); // union
            cost += w;       // add weight
            count++;         // increment edge count
        }    
    } 

    printf("Total Cost: %d\n", cost); 
} 

int main() 
{ 
    // edge list: {source, destination, weight}
    int edges[E][3] = { 
        {0, 1, 2}, {0, 2, 3}, {1, 2, 5}, 
        {1, 3, 3}, {2, 4, 4}, {3, 4, 2}
    }; 

    kruskal(edges); // function call

    return 0; // end program
}
