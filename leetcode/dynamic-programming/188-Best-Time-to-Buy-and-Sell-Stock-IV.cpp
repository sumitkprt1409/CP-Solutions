class Solution {
public:
    int Helper(int idx, vector<int> &prices, int buy, int no, int &target, vector<vector<vector<int>>> &dp){
        int n = prices.size();

        if(idx == n || no == target){
            return 0;
        }

        if(dp[idx][buy][no] != -1){
            return dp[idx][buy][no];
        }

        int p1 = 0, p2 = 0;
        if(buy){
            p1 = max(Helper(idx+1, prices, 0, no, target, dp) - prices[idx], Helper(idx+1, prices, 1, no, target, dp));
        }
        else{
            p2 = max(Helper(idx+1, prices, 1, no+1, target, dp) + prices[idx], Helper(idx+1, prices, 0, no, target, dp));
        }

        return dp[idx][buy][no] = max(p1, p2);
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k, -1)));
        return Helper(0, prices, 1, 0, k, dp);
    }
};