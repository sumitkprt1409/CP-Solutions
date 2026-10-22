class Solution {
public:
    int Helper(vector<int> &nums){
        int n = nums.size();
        vector<int> v = nums;
        int cnt = 1;

        for(int i=0; i<n; i++){
            v.push_back(nums[i]);
        }

        for(int i=1; i<v.size(); i++){
            if(v[i] < v[i-1]){
                cnt = 1;
            }
            else{
                cnt++;
                if(cnt == n){
                    return i+1-n;
                }
            }
        }

        cnt = 1;

        for(int i=1; i<v.size(); i++){
            if(v[i] > v[i-1]){
                cnt = 1;
            }
            else{
                cnt++;
                if(cnt == n){
                    return i+2-n;
                }
            }
        }

        return 1e9;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        int a = Helper(nums);
        reverse(nums.begin(), nums.end());
        int b = Helper(nums);

        int ans = min(a, b+1);

        if(ans == 1e9){
            return -1;
        }

        return ans;
    }
};