class Solution {
public:
    bool DFS(int curr, vector<vector<int>> &edges, vector<int> &visited, vector<int> &ans){
        if(visited[curr] == 1){
            return false;
        }

        if(visited[curr] == 2){
            return true; 
        }

        visited[curr] = 1;

        for(auto x : edges[curr]){
            if(!DFS(x, edges, visited, ans)){
                 return false;
            }
        }

        visited[curr] = 2;
        ans.push_back(curr);
        return true;
    }


    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<vector<int>> edges(num);
        for(int i=0; i<pre.size(); i++){
            int a = pre[i][0];
            int b = pre[i][1];

            edges[b].push_back(a);
        }

        vector<int> visited(num, 0);
        vector<int> ans;

        for(int i=0; i<num; i++){
            if(!visited[i]){
                if(!DFS(i, edges, visited, ans)){
                    return {};
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};