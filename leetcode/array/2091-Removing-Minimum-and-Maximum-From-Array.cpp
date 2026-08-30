class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int mini = INT_MAX;
        int less = 0;
        int high = 0;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            if(nums[i] < mini){
                mini = nums[i];
                less = i;
            }

            if(nums[i] > maxi){
                maxi = nums[i];
                high = i;
            }
        }

        int ans = 0;
        left = min(less, high);
        right = max(less, high);

        ans = min(right+1, min(n-left, left+1+n-right));
        return ans;

    }
};