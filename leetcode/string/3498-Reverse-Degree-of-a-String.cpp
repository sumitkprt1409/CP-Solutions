class Solution {
public:
    int reverseDegree(string s) {
        long long ans = 0;

        int n = s.size();
        for(int i=0; i<n; i++){
            int temp = (int)(s[i] - 'a');
            temp = 26 - temp;
            ans += (i+1)*temp;
        }

        return ans;
    }
};