#include <stdio.h>

int main() {
    int n;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);

    int a[n][n];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    int q[50], f = 0, r = 0, v[50] = {0}, s;
    printf("Enter source: ");
    scanf("%d", &s);

    q[r++] = s;
    v[s] = 1;

    printf("Broadcast order: ");
    while (f < r) {
        int u = q[f++];
        printf("%d ", u);

        for (int i = 0; i < n; i++) {
            if (a[u][i] && !v[i]) {
                v[i] = 1;
                q[r++] = i;
            }
        }
    }

    return 0;
}

