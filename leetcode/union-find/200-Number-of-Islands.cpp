class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for(int k=0; k<4; k++){
            int x = i + dx[k];
            int y = j + dy[k];

            dfs(x, y, grid);
        }
    }


    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }



        return cnt;

    }
};