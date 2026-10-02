class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        int n = nums.size();
        

        long long ans = -1e9;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                long long a = nums[i];
                long long b = nums[j];
                long long temp =  (a*b)/(pow(__gcd(a, b), 2));
                ans = max(ans, temp);
            }
        }

        return ans;
    }    
};