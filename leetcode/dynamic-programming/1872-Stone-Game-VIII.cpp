class Solution {
public:
    // int Helper(int i, vector<int> &prefix, int n, vector<int> &dp){
    //     if(i == n-1){
    //         return 0;
    //     }

    //     if(i != -1 && dp[i] != INT_MIN){
    //         return dp[i];
    //     }


    //     int max_diff = INT_MIN;
    //     for(int j=i+1; j<n; j++){
    //         if(j == 0){
    //             continue;
    //         }
    //         int a = prefix[j];
    //         int b = Helper(j, prefix, n, dp);

    //         int diff = a - b;
    //         max_diff = max(max_diff, diff);
    //     }

    //     if(i != -1){
    //         dp[i] = max_diff;
    //     }

    //     return max_diff;

    // }


    int stoneGameVIII(vector<int>& stones) {

        int n = stones.size();

        vector<int> prefix(n);
        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        int ans = prefix[n - 1];

        for (int i = n - 2; i >= 1; i--) {
            ans = max(ans, prefix[i] - ans);
        }

        return ans;








        // int n = stones.size();
        
        // vector<int> prefix(n);
        // if(n == 2){
        //     int ans = stones[0] + stones[1];
        //     return ans;
        // }
        // prefix[0] = stones[0];
        // for(int i=1; i<n; i++){
        //     prefix[i] += prefix[i-1] + stones[i];
        // }

        // vector<int> dp(n, INT_MIN);
        
        // // int ans = INT_MIN;
        // // for(int i=1; i<n; i++){
        // //     int a = prefix[i];
        // //     int b = prefix[n-1];
        // //     ans = max(ans, a-b);
        // // }

        // // ans = max(ans, prefix[n-1]-0);
        // // return ans;
        // dp[n-1] = 0;

        // int ans = INT_MIN;
        // for(int i=n-2; i>=-1; i--){

        //     int max_diff = INT_MIN;
        //     for(int j=i+1; j<n; j++){
        //         if(j == 0){
        //             continue;
        //         }
        //         int a = prefix[j];
        //         int b = dp[j];

        //         int diff = a - b;
        //         max_diff = max(max_diff, diff);
        //     }

        //     if(i != -1){
        //         dp[i] = max_diff;
        //     }
        //     else{
        //         ans = max_diff;
        //     }
        // }

        // return ans;






        
        //return Helper(-1, prefix, n, dp);

    }
};