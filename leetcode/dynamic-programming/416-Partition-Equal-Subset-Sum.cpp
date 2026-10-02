class Solution {
public:

    bool Helper(int idx, vector<int> &nums, int k, int sum, vector<vector<int>> &dp){
        int n = nums.size();

        if(idx < 0 || sum > k){
            return false;
        }
        if(sum == k){
            return true;
        }

        if(dp[idx][sum] != -1){
            return dp[idx][sum];
        }

        // take;
        bool take = Helper(idx-1, nums, k, sum+nums[idx], dp);

        //nottake;
        bool not_take = Helper(idx-1, nums, k, sum, dp);

        return dp[idx][sum] = (take || not_take);

    }

    bool canPartition(vector<int>& nums) {
        int k = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            k += nums[i];
        }

        if(k%2 != 0){
            return false;
        }
        vector<vector<int>> dp(n, vector<int> ((k/2)+5, -1));
        //-1 --> not visited
        //1 --> true
        //0 --> false
        return Helper(n-1, nums, k/2, 0, dp);
    }
};