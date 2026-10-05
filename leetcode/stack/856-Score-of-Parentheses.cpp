class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int cnt = 0;
        int score = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                cnt++;
            }
            else{
                cnt--;

                if(s[i-1] == '('){
                    score += (1<<cnt);
                }
            }
        }

        return score;
    }
};