class Solution {
public:
    long long sum = 0;
    void dfs(vector<vector<int>> &grid, int x, int y){
        int n = grid.size();
        int m = grid[0].size();

        if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0){
            return;
        }

        sum += grid[x][y];
        grid[x][y] = 0;

        dfs(grid, x+1, y);
        dfs(grid, x, y+1);
        dfs(grid, x-1, y);
        dfs(grid, x, y-1);

    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int ans = 0;
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] > 0){
                    sum = 0;
                    dfs(grid, i, j);

                    if(sum%k == 0){
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};