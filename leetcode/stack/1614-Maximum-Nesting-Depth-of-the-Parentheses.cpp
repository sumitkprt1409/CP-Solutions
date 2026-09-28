class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int n = s.size();
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                cnt++;
            }
            else if(s[i] == ')'){
                cnt--;
            }

            maxi = max(maxi, cnt);
        }

        return maxi;
    }
};