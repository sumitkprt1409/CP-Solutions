class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        int num = k;
        int ans = k;
        sort(nums.begin(), nums.end());
        int idx = 0;
        for(int i=0; i<n; i++){
            if(num == nums[i]){
                num += k;
                idx = i;
            }
        }
        
        return num;
    }
};