class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<int> dist(V, INT_MAX);
        vector<pair<int, int>> adj[V];
        
        for(auto x : edges){
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
                //dist, node
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > pq;
        pq.push({0, src});
        dist[src] = 0;
        
        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(distance > dist[node]){
                continue;
            }
            
            for(auto x : adj[node]){
                int v = x.first;
                int wt = x.second;
                
                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                    
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};