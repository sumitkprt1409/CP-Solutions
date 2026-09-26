class Solution {
public:
    int Helper(int idx, vector<int> &nums, int target, int sum){
        int n = nums.size();
        if(idx == n){
            if(sum == target){
                return 1;
            }
            return 0;
        }

        // +ve;
        int add = Helper(idx+1, nums, target, sum + nums[idx]);

        //-ve;
        int sub = Helper(idx+1, nums, target, sum - nums[idx]);

        return add + sub;
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        return Helper(0, nums, target, 0);
    }
};