class Solution {
public:
    int Helper(string &s, string t, int i, int j, vector<vector<int>> &dp){
        if(j == t.size()){
            return 1;
        }

        if(i == s.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        // take
        if(s[i] == t[j]){
            ans += Helper(s, t, i+1, j+1, dp);
        }

        //not take

        ans += Helper(s, t, i+1, j, dp);

        return dp[i][j] = ans;
    }


    int numDistinct(string s, string t) {
        //return Helper(s, t, 0, 0, dp);
        int n = s.size();
        int m = t.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

        // t is empty → 1 subsequence
        for(int i = 0; i <= n; i++) {
            dp[i][m] = 1;
        }

        // s is empty and t is non-empty → 0
        for(int j = 0; j < m; j++) {
            dp[n][j] = 0;
        }

        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {

                // Don't take s[i]
                dp[i][j] = dp[i + 1][j];

                // Take s[i]
                if(s[i] == t[j]) {
                    dp[i][j] += dp[i + 1][j + 1];
                }

                dp[i][j] = min(dp[i][j], (long long)INT_MAX);
            }
        }

        return (int)dp[0][0];

    }
};