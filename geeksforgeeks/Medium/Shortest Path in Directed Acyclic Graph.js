class Solution {
  public:
  
  void topoSort(int node, vector<pair<int, int>> edges[], stack<int> &st, vector<int> &visited){
      visited[node] = 1;
      
      for(auto x : edges[node]){
          int v = x.first;
          if(!visited[v]){
              topoSort(v, edges, st, visited);
          }
      }
      
      st.push(node);
  }
  
  
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        // code here
        vector<pair<int, int>> adj[V];
        for(auto x : edges){
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            adj[u].push_back({v, wt});
        }
        
        vector<int> visited(V, 0);
        stack<int> st;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                topoSort(i, adj, st, visited);
            }
        }
        
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(dist[node] == INT_MAX){
                continue;
            }
            
            for(auto x : adj[node]){
                int v = x.first;
                int wt = x.second;
                
                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        for(int i=0; i<V; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        
        
        
        return dist;
    }
};
