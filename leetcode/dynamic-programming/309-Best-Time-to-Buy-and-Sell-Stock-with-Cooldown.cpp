class Solution {
public:
    int Helper(int idx, vector<int> &prices, int buy, vector<vector<int>> &dp){
        int n = prices.size();

        if(idx >= n){
            return 0;
        }

        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }

        int p1 = 0, p2 = 0;
        
        if(buy){
            p1 = max(Helper(idx+1, prices, 0, dp) - prices[idx], Helper(idx+1, prices, 1, dp));
        }
        else{
            p2 = max(Helper(idx+2, prices, 1, dp) + prices[idx], Helper(idx+1, prices, 0, dp));
        }

        return dp[idx][buy] = max(p1, p2);
    }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));

        return Helper(0, prices, 1, dp);
    }
};