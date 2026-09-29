class Solution {
public:
    int n, m;

    bool Helper(int i, int j, vector<vector<char>>& grid,
                vector<vector<vector<int>>>& dp, int bal) {

        // Invalid balance
        if (bal < 0)
            return false;

        // More ')' than '('
        if (bal > n + m)
            return false;

        // Destination
        if (i == n - 1 && j == m - 1) {
            return bal == 0;
        }

        if (dp[i][j][bal] != -1)
            return dp[i][j][bal];

        // Move down
        if (i + 1 < n) {
            int newBal = bal + (grid[i + 1][j] == '(' ? 1 : -1);

            if (Helper(i + 1, j, grid, dp, newBal))
                return dp[i][j][bal] = true;
        }

        // Move right
        if (j + 1 < m) {
            int newBal = bal + (grid[i][j + 1] == '(' ? 1 : -1);

            if (Helper(i, j + 1, grid, dp, newBal))
                return dp[i][j][bal] = true;
        }

        return dp[i][j][bal] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // Path length must be even
        if ((n + m - 1) % 2 != 0)
            return false;

        // Starting cell must be '('
        if (grid[0][0] != '(')
            return false;

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(
                m,
                vector<int>(n + m + 1, -1)
            )
        );

        return Helper(0, 0, grid, dp, 1);
    }
};

















// class Solution {
// public:
    
//     bool Helper(int i, int j, vector<vector<char>>& grid, int st) {
//         int n = grid.size();
//         int m = grid[0].size();

//         // Invalid balance
//         if (st < 0)
//             return false;

//         // Destination
//         if (i == n - 1 && j == m - 1 && st == 0)
//             return true;

//         int dx[] = {0, 1};
//         int dy[] = {1, 0};

//         for (int k = 0; k < 2; k++) {
//             int x = i + dx[k];
//             int y = j + dy[k];

//             if (x < 0 || x >= n || y < 0 || y >= m)
//                 continue;

//             if (grid[x][y] == '(') {
//                 if (Helper(x, y, grid, st + 1))
//                     return true;
//             }
//             else {
//                 if (Helper(x, y, grid, st - 1))
//                     return true;
//             }
//         }

//         return false;
//     }

//     bool hasValidPath(vector<vector<char>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();

//         // Path length must be even
//         if ((n + m - 1) % 2 != 0)
//             return false;

//         // First character must be '('
//         if (grid[0][0] == ')')
//             return false;

//         return Helper(0, 0, grid, 1);
//     }
// };