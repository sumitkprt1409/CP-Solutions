class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        map<int, int> mpp;
        int n = nums.size();

        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }

        int middle = nums[n/2];

        return mpp[middle] == 1;
    }
};