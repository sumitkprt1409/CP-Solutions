class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int a = 0;
        int b = 0;

        for(int i=0; i<n; i++){
            if(s[i] == 'a'){
                a++;
            }
            else{
                b++;
            }
        }

        if(a == 0 || b == 0){
            return true;
        }

        for(int i=0; i<n; i++){
            if(s[i] == 'a'){
                a--;
            }
            else{
                if(a > 0){
                    return false;
                }
            }
        }

        return true;

    }
};