#include <stdio.h>
#define INF 999

int main() {
    int n, s;

    printf("Enter vertices: ");
    scanf("%d", &n);

    int c[n][n];
    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    printf("Enter source: ");
    scanf("%d", &s);

    int d[n], vis[n];

    // Initialize distance and visited arrays
    for (int i = 0; i < n; i++) { 
        d[i] = c[s][i]; 
        vis[i] = 0; 
    }
    vis[s] = 1;

    // Dijkstra's Algorithm
    for (int i = 1; i < n; i++) {
        int u = -1, min = INF;

        // Find the vertex with the minimum distance
        for (int j = 0; j < n; j++) {
            if (!vis[j] && d[j] < min) { 
                min = d[j]; 
                u = j; 
            }
        }

        vis[u] = 1;

        // Update distances for neighboring vertices
        for (int j = 0; j < n; j++) {
            if (!vis[j] && (d[u] + c[u][j] < d[j])) {
                d[j] = d[u] + c[u][j];
            }
        }
    }

    // Print shortest paths
    for (int i = 0; i < n; i++) {
        printf("Shortest path %d to %d = %d\n", s, i, d[i]);
    }

    return 0;
}

