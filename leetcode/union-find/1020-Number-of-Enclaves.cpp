class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dist){
        int n = grid.size();
        int m = grid[0].size();

        if(grid[i][j] == 0 || dist[i][j] == 1){
            return;
        }
        
        dist[i][j] = 1;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int k=0; k<4; k++){
            int x = i + dx[k];
            int y = j + dy[k];

            if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1){
                dfs(x, y, grid, dist);
            }
        }
    }



    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int> (m, 0));


        for(int i=0; i<m; i++){
            if(grid[0][i] == 1){
                dfs(0, i, grid, dist);
            }
        }

        for(int i=0; i<m; i++){
            if(grid[n-1][i] == 1){
                dfs(n-1, i, grid, dist);
            }
        }

        for(int i=0; i<n; i++){
            if(grid[i][0] == 1){
                dfs(i, 0, grid, dist);
            }
        }

        for(int i=0; i<n; i++){
            if(grid[i][m-1] == 1){
                dfs(i, m-1, grid, dist);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dist[i][j] == 1){
                    grid[i][j] = 0;
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    cnt++;
                }
            }
        }

        return cnt;

    }
};