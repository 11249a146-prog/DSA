//Aim: To develop a C program using Dijkstra’s Algorithm for determining the minimum distance from a selected source vertex to every other vertex in a weighted graph.//
//program//
#include <stdio.h>

#define V 5
#define INF 999999

/* Function to find the vertex with minimum distance */
int findMin(int dist[], int visit[])
{
    int min = INF, pos = -1;

    for (int i = 0; i < V; i++)
    {
        if (visit[i] == 0 && dist[i] < min)
        {
            min = dist[i];
            pos = i;
        }
    }
    return pos;
}

void dijkstra(int graph[V][V])
{
    int dist[V], visit[V];

    /* Initial values */
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visit[i] = 0;
    }

    dist[0] = 0;   // source vertex

    for (int i = 0; i < V - 1; i++)
    {
        int u = findMin(dist, visit);

        if (u == -1)
            break;

        visit[u] = 1;

        for (int j = 0; j < V; j++)
        {
            if (visit[j] == 0 && graph[u][j] != 0 &&
                dist[u] != INF &&
                dist[j] > dist[u] + graph[u][j])
            {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    printf("\nVertex \t Distance from Source (0)\n");

    for (int i = 0; i < V; i++)
    {
        printf("%d --> %d\n", i, dist[i]);
    }
}

int main()
{
    int graph[V][V] =
    {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    dijkstra(graph);

    return 0;
}
