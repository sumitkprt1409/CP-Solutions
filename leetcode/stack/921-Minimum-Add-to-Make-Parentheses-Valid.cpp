class Solution {
public:
    int minAddToMakeValid(string s) {
        int num = 0;
        int ans = 0;
        for (char ch : s) {
            if(ch == '('){
                num++;
            }
            else if(num > 0){
                num--;
            }
            else{
                ans++;
            }
        }

        return num + ans;
    }
};