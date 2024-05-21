#include <stdio.h>
#include <stdbool.h>
int ver;
void dijkstra(int G[][ver], int src, int size);
int findMinDistance(int dist[], bool vset[], int size);
void display(int dist[], int size);

void dijkstra(int G[][ver], int src, int size)
{
    int dist[size];
    bool vset[size];

    for (int i = 0; i < size; i++)
    {
        dist[i] = 999;
        vset[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < size - 1; count++)
    {
        int u = findMinDistance(dist, vset, size);
        vset[u] = true;

        for (int i = 0; i < size; i++)
        {
            if (!vset[i] && G[u][i] && dist[u] != 999 && dist[u] + G[u][i] < dist[i])
            {
                dist[i] = dist[u] + G[u][i];
            }
        }
    }

    display(dist, size);
}

int findMinDistance(int dist[], bool vset[], int size)
{
    int min = 999;
    int minIndex = -1;

    for (int i = 0; i < size; i++)
    {
        if (!vset[i] && dist[i] < min)
        {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void display(int dist[], int size)
{

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main()
{
    int edges;
    printf("Enter number of vertices: ");
    scanf("%d", &ver);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    int G[ver][ver];

    // Initialize graph matrix with 0
    for (int i = 0; i < ver; i++)
    {
        for (int j = 0; j < ver; j++)
        {
            G[i][j] = 0;
        }
    }

    printf("Enter the edges and their weights:\n");
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        printf("Enter edge %d (source destination weight): ", i + 1);
        scanf("%d %d %d", &u, &v, &w);
        G[u][v] = w;
    }

    int src;
    printf("Starting Vertex: ");
    scanf("%d", &src);

    dijkstra(G, src, ver);

    return 0;
}