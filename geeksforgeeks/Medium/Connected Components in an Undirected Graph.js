class Solution {
public:

    void dfs(int curr, vector<vector<int>>& adj,
             vector<int>& visited, vector<int>& arr) {

        visited[curr] = 1;
        arr.push_back(curr);

        for (auto x : adj[curr]) {
            if (!visited[x]) {
                dfs(x, adj, visited, arr);
            }
        }
    }

    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        // Convert edge list to adjacency list
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> ans;
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++) {

            if (!visited[i]) {

                vector<int> arr;

                dfs(i, adj, visited, arr);

                ans.push_back(arr);
            }
        }

        return ans;
    }
};