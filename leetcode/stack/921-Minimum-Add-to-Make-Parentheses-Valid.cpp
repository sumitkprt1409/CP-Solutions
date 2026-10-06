class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int cnt = 0;
        int ans = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                cnt++;
            }
            else{
                cnt--;
            }

            if(cnt < 0){
                ans += abs(cnt);
                cnt = 0;
            }
        }
        ans += abs(cnt);
        // int cnt2 = 0;

        // for(int i=n-1; i>=0; i--){
        //     if(s[i] == ')'){
        //         cnt++;
        //     }
        //     else{
        //         cnt--;
        //     }

        //     if(cnt < 0){
        //         ans += abs(cnt);
        //         cnt = 0;
        //     }
        // }

        return ans;
    }
};