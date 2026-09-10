class Solution {
public:
    void dfs(int curr, vector<vector<int>> &edges, vector<int> &visited){
        visited[curr] = 1;
        for(int i=0; i<edges.size(); i++){
            if(!visited[i] && edges[curr][i]){
                dfs(i, edges, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       int cnt = 0;
       int n = isConnected.size();
       vector<int> visited(n, 0);
       for(int i=0; i<n; i++){
            if(!visited[i]){
                cnt++;
                dfs(i, isConnected, visited);
            }
       } 

       return cnt;
    }
};