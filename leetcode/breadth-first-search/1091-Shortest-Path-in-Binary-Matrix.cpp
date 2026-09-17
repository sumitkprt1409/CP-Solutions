class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1){
            return -1;
        }
                // node, step;
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int> (m, -1));
        q.push({0, 0});
        dist[0][0] = 0;

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    int x1 = x + i;
                    int y1 = y + j;

                    if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m){

                    
                        if(grid[x1][y1] == 1){
                            continue;
                        }
                        
                        if(dist[x1][y1] == -1){
                            dist[x1][y1] = dist[x][y] + 1;

                            q.push({x1, y1});
                        }

                    }
                }
            }
        }

        if(dist[n-1][m-1] == -1){
            return -1;
        }

        return dist[n-1][m-1] + 1;

    }
};