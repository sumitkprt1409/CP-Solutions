class Solution {
public:
    int Helper(int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i == m-1 && j == n-1){
            return 1;
        }

        if(i < 0 || i >= m || j < 0 || j >= n){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = Helper(i+1, j, m, n, dp);

        int down = Helper(i, j+1, m, n, dp);

        return dp[i][j] = right + down;

    }

    int uniquePaths(int m, int n) {

        //menoization
        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // return Helper(0, 0, m, n, dp);

        //tabular
        vector<vector<int>> dp(m, vector<int> (n, -1));
        dp[m-1][n-1] = 1;

        for(int i=m-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                int right = dp[i+1][j];
                int down = dp[i][j+1];

                dp[i][j] = right + down;
            }
        }

        return abs(dp[0][0]);

    }
};