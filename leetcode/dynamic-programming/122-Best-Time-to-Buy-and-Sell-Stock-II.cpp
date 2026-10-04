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
            p2 = max(Helper(idx+1, prices, 1, dp) + prices[idx], Helper(idx+1, prices, 0, dp));
        }

        return dp[idx][buy] = max(p1, p2);
    }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> prev(2, 0), curr(2, 0);

        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<2; buy++){
                int p1 = 0, p2 = 0;
                if(buy){
                    p1 = max(prev[0] - prices[i], prev[1]);
                }
                else{
                    p2 = max(prev[1] + prices[i], prev[0]);
                }

                curr[buy] = max(p1, p2);
            }
            prev = curr;
        }

        return prev[1];



















        // vector<vector<int>> dp(n+1, vector<int> (2, -1));
        // //return Helper(0, prices, 1, dp);

        // dp[n][1] = 0;
        // dp[n][0] = 0;

        // for(int i=n-1; i>=0; i--){
        //     for(int buy=0; buy<2; buy++){
        //         int p1 = 0, p2 = 0;
        //         if(buy){
        //             p1 = max(dp[i+1][0] - prices[i], dp[i+1][1]);
        //         }
        //         else{
        //             p2 = max(dp[i+1][1] + prices[i], dp[i+1][0]);
        //         }

        //         dp[i][buy] = max(p1, p2);
        //     }
        // }

        // return dp[0][1];
    }
};