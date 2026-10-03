class Solution {
public:
    int longestValidParentheses(string s) {
        //vector<int> open;
        int n = s.size();

        int open = 0;
        int close = 0;
        int ans = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                open++;
            }
            else{
                close++;
            }

            if(open == close){
                ans = max(ans, open + close);
            }
            if(close > open){
                open = 0;
                close = 0;
            }
        }

        open = 0;
        close = 0;

        for(int i=n-1; i>=0; i--){
            if(s[i] == ')'){
                open++;
            }
            else{
                close++;
            }

            if(open == close){
                ans = max(ans, open + close);
            }
            if(close > open){
                open = 0;
                close = 0;
            }
        }

        return ans;








        // for(int i=0; i<n; i++){
        //     if(s[i] == '('){
        //         open.push_back(i);
        //     }
        // }
        
        // int ans = 0;

        // for(int i=0; i<open.size(); i++){
        //     int j = open[i];
        //     int cnt = 0;
        //     bool flag = false;
        //     while(j < n){
        //         if(s[j] == '('){
        //             cnt++;
        //             flag = true;
        //         }
        //         else{
        //             cnt--;
        //         }

        //         if(cnt < 0){
        //             break;
        //         }
        //         if(cnt == 0){
        //             ans = max(ans, j-open[i]+1);
        //         }
        //         j++;
        //     }
            
        // }

        //return ans;

    }
};