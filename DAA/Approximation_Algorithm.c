//Aim: To write and implement an approximation algorithm for the Vertex Cover Problem that selects a near-minimum set of vertices covering all edges of a graph.//
//program//
#include <stdio.h>

#define V 5   // Number of vertices

/* Function to find approximate Vertex Cover */
void vertexCover(int graph[V][V])
{
    int mark[V];

    /* Initialize all vertices as not selected */
    for (int i = 0; i < V; i++)
    {
        mark[i] = 0;
    }

    /* Check all edges of graph */
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] == 1 && mark[i] == 0 && mark[j] == 0)
            {
                mark[i] = 1;   // Select first vertex
                mark[j] = 1;   // Select second vertex
            }
        }
    }

    printf("Approximate Vertex Cover: ");

    int count = 0;

    /* Display selected vertices */
    for (int i = 0; i < V; i++)
    {
        if (mark[i] == 1)
        {
            printf("%d ", i);
            count++;
        }
    }

    printf("\nTotal vertices in the cover: %d\n", count);
}

int main()
{
    /* Graph represented using adjacency matrix */
    int graph[V][V] =
    {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    printf("Executing Vertex Cover Approximation...\n");

    vertexCover(graph);   // Function call

    return 0;
}
