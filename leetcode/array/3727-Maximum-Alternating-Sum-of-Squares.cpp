class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] < 0){
                nums[i] = -1*nums[i];
            }
        }

        sort(nums.begin(), nums.end());

        long long ans = 0;
        int i=n-1;
        int cnt = 0;
        int take = n/2;
       
        
        for(int i=take; i<n; i++){
            ans += 1LL*nums[i]*nums[i];
        }

        for(int i=0; i<take; i++){
            ans -= 1LL*nums[i]*nums[i];
        }


        return ans;



    }
};