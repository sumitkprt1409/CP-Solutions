class Solution {
public:
    bool bfs(int curr, vector<vector<int>> &edges, vector<int> &visited){

        if(visited[curr] == 1){
            return false;
        }

        if(visited[curr] == 2){
            return true;
        }

        visited[curr] = 1;

        for(auto x : edges[curr]){
            if(!bfs(x, edges, visited)){
                return false;
            }
        }

        visited[curr] = 2;
        return true;
    }


    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> edges(num);

        for(int i=0; i<pre.size(); i++){
            int a = pre[i][0];
            int b = pre[i][1];

            edges[b].push_back(a);
        }

        vector<int> visited(num, 0);

        for(int i=0; i<num; i++){
            if(!bfs(i, edges, visited)){
                return false;
            }
        }

        return true;
    }
};