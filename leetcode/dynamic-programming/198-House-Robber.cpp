class Solution {
public:
    int Helper(int idx, vector<int> &nums, vector<int> &dp){
        int n = nums.size();

        if(idx >= n){
            return 0;
        }

        //take 
        int take = nums[idx] + Helper(idx + 2, nums, dp);

        int not_take = Helper(idx+1, nums, dp);

        return dp[idx] = max(take, not_take);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n+1, -1);

        // return Helper(0, nums, dp);

        vector<int> dp(n, 0);
        dp[n-1] = 0;

        for(int i=n-1; i>=0; i--){
            int take = nums[i];
            if(i+2 < n){
                take += dp[i+2];
            }
            int not_take;
            if(i+1 < n){
                not_take = dp[i+1];
            } 

            dp[i] = max(take, not_take);
        } 

        return dp[0];

    }
};