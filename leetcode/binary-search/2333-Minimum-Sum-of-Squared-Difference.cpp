class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = k1+k2;

        vector<int> diff(1e6+1, 0);
        int maxdiff = 0;
        long long total = 0;

        for(int i=0; i<n; i++){
            int d = abs(nums1[i] - nums2[i]);
            diff[d]++;

            total += d;

            maxdiff = max(maxdiff, d);
        }

        if(total <= k){
            return 0;
        }

        for(int d=maxdiff; d>0 && k>0; d--){
            int m = min(k, (long long)diff[d]);

            diff[d] -= m;
            diff[d-1] += m;


            k -= m;
        }

        long long ans = 0;

        for(int i=1; i<=maxdiff; i++){
            ans += (long long)i*i*diff[i];
        }

        return ans;

    }
};