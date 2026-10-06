class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        int size = max(n, m);
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        dp[n][m] = 0;
        int ans = 0;

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){

                if(s1[i] == s2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                    ans = max(ans, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }

        
        
        return ans;
        
    }
};