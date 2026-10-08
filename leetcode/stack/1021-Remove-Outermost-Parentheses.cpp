class Solution {
public:
    string removeOuterParentheses(string s) {
      string ans = "";
        int n = s.size();
        int cnt = 0;
        int left = -1, right = -1;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                if(cnt == 0){
                    left = i;
                }
                cnt++;
            }
            else{
                cnt--;
                if(cnt == 0){
                    right = i;
                }
            }

            if(left != -1 && right != -1){
                ans += s.substr(left+1, right-left-1);
                left = -1;
                right = -1;
            }

        }

        return ans;

    }
};