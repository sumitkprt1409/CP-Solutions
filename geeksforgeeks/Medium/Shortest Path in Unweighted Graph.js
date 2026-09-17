class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        vector<int> adj[V];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        
        vector<int> visited(V, 0);
                //node, step;
        queue<pair<int, int>> q;
        q.push({src, 0});
        visited[src] = 1;
        
        while(!q.empty()){
            int node = q.front().first;
            int step = q.front().second;
            q.pop();
            
            if(node == dest){
                return step;
            }
            
            for(auto x : adj[node]){
                if(!visited[x]){
                    q.push({x, step+1});
                    visited[x] = 1;
                }
            }
        }
        
        return -1;
    }
};
