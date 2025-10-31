#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src) {
        vector<int> dist(V, 1e9);  // Distance array initialized to infinity
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;

                if (dis + edgeWt < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // For undirected graph
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    Solution obj;
    vector<int> dist = obj.dijkstra(V, adj, src);

    cout << "\nShortest distances from vertex " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "To " << i << " = " << dist[i] << endl;
    }

    return 0;
}

