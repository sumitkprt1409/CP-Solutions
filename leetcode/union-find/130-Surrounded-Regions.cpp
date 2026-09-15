class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &board, vector<vector<int>> &dist){
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int n = board.size();
        int m = board[0].size();
        
        if(board[i][j] =='X'){
            return;
        }
        else{
            dist[i][j] = 1;
        }

        for(int k=0; k<4; k++){
            int x = i + dx[k];
            int y = j + dy[k];

            if(x >= 0 && x < n && y >= 0 && y < m && dist[x][y] == 0){
                dfs(x, y, board, dist);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> dist(n, vector<int> (m, 0));

        for(int i=0; i<m; i++){
            if(board[0][i] != 'X'){
                dfs(0, i, board, dist);
            }  
        }
        for(int i=0; i<m; i++){
            if(board[n-1][i] != 'X'){
                dfs(n-1, i, board, dist);
            }
        }
        for(int i=0; i<n; i++){
            if(board[i][0] != 'X'){
                dfs(i, 0, board, dist);
            }
        }
        for(int i=0; i<n; i++){
            if(board[i][m-1] != 0){
                dfs(i, m-1, board, dist);
            }
        }
        

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O' && dist[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }

        return;

    }
};