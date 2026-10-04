class Solution {
public:
    int Helper(int idx, vector<int> &prices, int buy, int &fee, vector<vector<int>> &dp){
        int n = prices.size();

        if(idx >= n){
            return 0;
        }

        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }

        int p1 = 0, p2 = 0;
        if(buy){
            p1 = max(Helper(idx+1, prices, 0, fee, dp) - prices[idx], Helper(idx+1, prices, 1, fee, dp));
        }
        else{
            p2 = max(Helper(idx+1, prices, 1, fee, dp) + prices[idx] - fee, Helper(idx+1, prices, 0, fee, dp));
        }

        return dp[idx][buy] = max(p1, p2);
    }


    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return Helper(0, prices, 1, fee, dp);
    }
};