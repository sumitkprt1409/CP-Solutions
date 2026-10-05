class Solution {
public:
    int Helper(int i, int j, string s1, string s2, vector<vector<int>> &dp){
        int n = s1.size();
        int m = s2.size();

        if(i == n || j == m){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s1[i] == s2[j]){
            return 1 + Helper(i+1, j+1, s1, s2, dp);
        }
        else{
            return dp[i][j] = max(Helper(i+1, j, s1, s2, dp), Helper(i, j+1, s1, s2, dp));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int size = max(n, m);

       vector<int> prev(size+1, 0), curr(size+1, 0);
        
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){

                if(text1[i] == text2[j]){
                    curr[j] = 1 + prev[j+1];
                }
                else{
                    curr[j] = max(prev[j], curr[j+1]);
                }
            }
            prev = curr;
        }

        return prev[0];












        // vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        // dp[n][m] = 0;
        
        // for(int i=n-1; i>=0; i--){
        //     for(int j=m-1; j>=0; j--){

        //         if(text1[i] == text2[j]){
        //             dp[i][j] = 1 + dp[i+1][j+1];
        //         }
        //         else{
        //             dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        //         }
        //     }
        // }

        // return dp[0][0];

















        // vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        // dp[n][m] = 0;
        
        // for(int i=n-1; i>=0; i--){
        //     for(int j=m-1; j>=0; j--){

        //         if(text1[i] == text2[j]){
        //             dp[i][j] = 1 + dp[i+1][j+1];
        //         }
        //         else{
        //             dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        //         }
        //     }
        // }

        // return dp[0][0];







        //return Helper(0, 0, text1, text2, dp);
    }
};