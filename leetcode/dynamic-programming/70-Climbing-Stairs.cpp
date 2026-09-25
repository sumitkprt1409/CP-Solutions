class Solution {
public:
    int climbStairs(int n) {
        int ans = 0;
        if(n <= 2){
            return n;
        }
        vector<int> dp(n+1, -1);
        dp[1] = 1, dp[2] = 2;

        int prev1 = 1, prev2 = 1;
        for(int i=2; i<=n; i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};