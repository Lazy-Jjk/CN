#include <stdio.h>
#define INF 999

int main() {
    int n;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);

    int cost[n][n];
    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    int dist[n][n], next[n][n];

    // Initialize distance and next-hop tables
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            dist[i][j] = cost[i][j];
            next[i][j] = j;
        }

    int updated = 1;

    // Distance Vector (Bellman-Ford iterative updates)
    while (updated) {
        updated = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next[i][j] = next[i][k];
                        updated = 1;
                    }
    }

    // Display routing tables
    for (int i = 0; i < n; i++) {
        printf("\nRouting table for node %d:\n", i);
        for (int j = 0; j < n; j++)
            printf("To %d via %d cost = %d\n", j, next[i][j], dist[i][j]);
    }

    return 0;
}

