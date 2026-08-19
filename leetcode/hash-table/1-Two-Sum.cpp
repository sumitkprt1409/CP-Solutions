class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // int n = nums.size();
        // map<int, int> mpp;
        // for(int i=0; i<n; i++){
        //     mpp[nums[i]] = i;
        // }
        // int a = -1, b = -1;
        // for(int i=0; i<n; i++){
        //     int num = target - nums[i];

        //     if(mpp.find(num) != mpp.end()){
        //         a = i;
        //         b = mpp[num];
        //         break;
        //     }
        // }

        // return {a, b};

        int n = nums.size();
        map<int, int> mpp;
        for(int i=0; i<n; i++){
            int num = nums[i];
            if(mpp.find(target - num) != mpp.end()){
                return {i, mpp[target-num]};
            }
            mpp[num] = i;
        }
        return {-1, -1};
    }
};