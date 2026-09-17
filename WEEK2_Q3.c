#include <stdio.h>

struct Edge
{
    int u;
    int v;
    int weight;
};

int find(int parent[], int x)
{
    while(parent[x] != x)
        x = parent[x];

    return x;
}

void unionSet(int parent[], int a, int b)
{
    int x = find(parent, a);
    int y = find(parent, b);

    parent[x] = y;
}

int main()
{
    struct Edge e[20], temp;
    int parent[20];
    int n, m, i, j;
    int count = 0, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (source destination weight):\n");

    for(i = 0; i < m; i++)
    {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].weight);
    }

    for(i = 0; i < n; i++)
        parent[i] = i;

    for(i = 0; i < m - 1; i++)
    {
        for(j = 0; j < m - i - 1; j++)
        {
            if(e[j].weight > e[j + 1].weight)
            {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    for(i = 0; i < m && count < n - 1; i++)
    {
        int x = find(parent, e[i].u);
        int y = find(parent, e[i].v);

        if(x != y)
        {
            printf("%d - %d = %d\n", e[i].u, e[i].v, e[i].weight);

            total = total + e[i].weight;
            unionSet(parent, x, y);
            count++;
        }
    }

    printf("Minimum cost = %d", total);

    return 0;
}