class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> k;
        for(int i=1; i*i<=n; i++){
            if(n%i == 0){
                k.push_back(i);
                if(n/i != i){
                    k.push_back(n/i);
                }
            }
        }

        int ans = 0;
        int num = k.size();

        for(int i=0; i<num; i++){
            int temp = k[i];
            int prev_max = INT_MIN;
            bool flag = true;

            for(int j=0; j<n; j+=temp){
                int cnt = 0;
                int mini = INT_MAX;
                int maxi = INT_MIN;

                for(int a=j; a<j+temp; a++){
                    if(a > j && nums[a-1] > nums[a]){
                        cnt++;
                    }
                    mini = min(mini, nums[a]);
                    maxi = max(maxi, nums[a]);
                }

                if(cnt == 1 && nums[j+temp-1] > nums[j] || prev_max > mini){
                    flag = false;
                    break;
                }
                else if(cnt > 1){
                    flag = false;
                    break;
                }
                prev_max = maxi;
            }

            if(flag){
                ans += temp;
            }
           
        }

        return ans;
    }
};