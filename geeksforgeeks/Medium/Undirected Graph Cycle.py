class Solution {
public:

    bool bfs(int start, vector<vector<int>>& adj,
             vector<int>& visited) {

        queue<pair<int, int>> q;

        q.push({start, -1});
        visited[start] = 1;

        while (!q.empty()) {

            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto neighbour : adj[node]) {

                if (!visited[neighbour]) {

                    visited[neighbour] = 1;
                    q.push({neighbour, node});
                }
                else if (neighbour != parent) {

                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        // Convert edge list -> adjacency list
        vector<vector<int>> adj(V);

        for (auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(V, 0);

        // Graph may have multiple components
        for (int i = 0; i < V; i++) {

            if (!visited[i]) {

                if (bfs(i, adj, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};