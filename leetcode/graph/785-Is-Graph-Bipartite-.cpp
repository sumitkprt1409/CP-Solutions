class Solution {
public:
    bool DFS(int curr, int color, vector<vector<int>> &graph, vector<int> &visited){
        visited[curr] = color;

        for(auto x : graph[curr]){
            if(visited[x] == -1){
                if(!DFS(x, color^1, graph, visited)){
                    return false;
                }
            }
            else if(visited[x] == color){
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph){
        int n = graph.size();
        vector<int> visited(n, -1);
        for(int i=0; i<n; i++){
            if(visited[i] == -1){
                if(!DFS(i, 0, graph, visited)){
                    return false;
                }
            }
        }
        return true;
    }
};