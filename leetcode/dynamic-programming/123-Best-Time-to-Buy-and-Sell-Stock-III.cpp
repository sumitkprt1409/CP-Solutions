class Solution {
public:
    int Helper(int idx, vector<int> prices, int buy, int no, vector<vector<vector<int>>> &dp){
        int n = prices.size();

        if(no >= 2 || idx == n){
            return 0;
        }

        if(dp[idx][buy][no] != -1){
            return dp[idx][buy][no];
        }

        int p1 = 0, p2 = 0;
        if(buy){
            p1 = max(Helper(idx+1, prices, 0, no, dp) - prices[idx], Helper(idx+1, prices, 1, no, dp));
        }
        else{
            p2 = max(Helper(idx+1, prices, 1, no+1, dp) + prices[idx], Helper(idx+1, prices, 0, no, dp));
        }

        return dp[idx][buy][no] = max(p1, p2);
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>> prev(2, vector<int> (3, 0));
        vector<vector<int>> curr(2, vector<int> (3, 0));
        //return Helper(0, prices, 1, 0, dp);


        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<2; buy++){
                for(int no=1; no<=2; no++){
                    int p1 = 0, p2 = 0;
                    if(buy == 1){
                        p1 = max(prev[0][no] - prices[idx], prev[1][no]);
                    }
                    else{
                        p2 = max(prev[1][no-1] + prices[idx], prev[0][no]);
                    }

                    curr[buy][no] = max(p1, p2);
                }
                prev = curr;
            }
        }


        
        return prev[1][2];







        
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));
        // //return Helper(0, prices, 1, 0, dp);


        // for(int idx=n-1; idx>=0; idx--){
        //     for(int buy=0; buy<2; buy++){
        //         for(int no=1; no<=2; no++){
        //             int p1 = 0, p2 = 0;
        //             if(buy == 1){
        //                 p1 = max(dp[idx+1][0][no] - prices[idx], dp[idx+1][1][no]);
        //             }
        //             else{
        //                 p2 = max(dp[idx+1][1][no-1] + prices[idx], dp[idx+1][0][no]);
        //             }

        //             dp[idx][buy][no] = max(p1, p2);
        //         }
        //     }
        // }


        
        // return dp[0][1][2];




    }
};