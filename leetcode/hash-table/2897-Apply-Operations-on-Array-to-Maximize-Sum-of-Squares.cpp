class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        const int MOD = 1e9+7;
        long long ans = 0;
        vector<int> bit(32, 0);

        for(int i=0; i<n; i++){
            int num = nums[i];
            for(int b=31; b>=0; b--){
                if(num & (1 << b)){
                    bit[b]++;
                }
            }
        }

        for(int i=0; i<k; i++){
            int num = 0;
            for(int i=31; i>=0; i--){
                if(bit[i] > 0){
                   num |= (1LL << i);
                    bit[i]--;
                }
            }
            ans = (ans + 1LL*num*num%MOD)%MOD;
        }



        return ans;
    }
};