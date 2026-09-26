class Solution {
public:
    int Helper(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        int n = matrix.size();
        int m = matrix[0].size();

        if(i >= n || i < 0 || j >= m || j < 0){
            return INT_MAX;
        }

        if(i == n-1){
            return matrix[i][j];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = Helper(i+1, j, matrix, dp);
        int diag = Helper(i+1, j+1, matrix, dp);
        int down = Helper(i+1, j-1, matrix, dp);

        return dp[i][j] = matrix[i][j] + min({right, diag, down});
    }



    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        int ans = INT_MAX;
        
        // for(int j=0; j<n; j++){
        //     ans = min(ans, Helper(0, j, matrix, dp));
        // }

        for(int i=0; i<m; i++){
            dp[n-1][i] = matrix[n-1][i];
        }

        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int right = INT_MAX, diag = INT_MAX, down = INT_MAX ;
                if(i+1 < n){
                    right = dp[i+1][j];
                }
                if(i+1 < n && j+1 < n){
                    diag = dp[i+1][j+1];
                }

                if(i+1 < n && j-1 >= 0){
                    down = dp[i+1][j-1];
                }
               
                dp[i][j] = matrix[i][j] + min({right, diag, down});

            }
        }

        for(int i=0; i<n; i++){
            ans = min(ans, dp[0][i]);
        }

        return ans;
    }
};