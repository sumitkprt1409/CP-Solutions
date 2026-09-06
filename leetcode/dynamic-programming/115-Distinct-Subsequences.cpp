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
        vector<vector<int>> dp(1100, vector<int> (1100, -1));
        return Helper(s, t, 0, 0, dp);


    }
};