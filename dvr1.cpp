#include <bits/stdc++.h>
using namespace std;

void broadcast(vector<vector<int>> &adj, int src, int n) {
    vector<int> visited(n, 0);
    queue<int> q;

    visited[src] = 1;
    q.push(src);

    cout << "\nBroadcast starting from Node " << src << ":\n";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << "Message sent from Node " << node << " to: ";

        bool sent = false;
        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                cout << i << " ";
                visited[i] = 1;
                q.push(i);
                sent = true;
            }
        }

        if (!sent)
            cout << "None";

        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    cout << "Enter adjacency matrix (" << n << "x" << n << "):\n";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    int src;
    cout << "Enter source node for broadcast: ";
    cin >> src;

    broadcast(adj, src, n);
    return 0;
}


