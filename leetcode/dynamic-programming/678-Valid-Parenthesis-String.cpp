class Solution {
public:
   
    bool checkValidString(string s) {
        int cnt = 0;
        int n = s.size();
        int star = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '*'){
                star++;
            }
            else if(s[i] == '('){
                cnt++;
            }
            else{
                cnt--;
            }

            if(cnt < 0){
                if(star >= abs(cnt)){
                    star -= abs(cnt);
                    cnt = 0;
                }
                else{
                    return false;
                }
            }
        }

        int cnt1 = 0;
        int star1 = 0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '*'){
                star1++;
            }
            else if(s[i] == ')'){
                cnt1++;
            }
            else{
                cnt1--;
            }

            if(cnt1 < 0){
                if(star1 >= abs(cnt1)){
                    star1 -= abs(cnt1);
                    cnt1 = 0;
                }
                else{
                    return false;
                }
            }
        }

        if(cnt == 0 || cnt1 == 0){
            return true;
        }

        if(star >= abs(cnt) || star1 >= abs(cnt1)){
            return true;
        }

        return false;
    }
};