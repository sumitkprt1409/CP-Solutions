class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mini(n), maxi(n);
        maxi[0] = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] > maxi[i-1]){
                maxi[i] = nums[i];
            }
            else{
                maxi[i] = maxi[i-1];
            }
        }

        mini[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            if(nums[i] < mini[i+1]){
                mini[i] = nums[i];
            }
            else{
                mini[i] = mini[i+1];
            }
        }

        for(int i=0; i<n; i++){
            if(maxi[i] - mini[i] <= k){
                return i;
            }
        }

        return -1;







        // int ans = 0;
        // int n = nums.size();
        // for(int i=0; i<n; i++){
        //     int maxi = *max_element(nums.begin(), nums.begin()+i);
        //     int mini = *min_element(nums.begin()+i, nums.end());

        //     if(maxi - mini <= k){
        //         return i;
        //     }
        // }

        // return -1;
        //T.C = O(n^2);
        //S.C = O(n);
    }
};