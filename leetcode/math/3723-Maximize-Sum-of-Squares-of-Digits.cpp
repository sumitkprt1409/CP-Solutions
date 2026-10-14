class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";

        if(num*9 < sum){
            return ans;
        }

        while(num--){
            int a = min(9, sum);
            sum -= 9;
            if(a < 0){
                ans += to_string(0);
            }
            else{
                ans += to_string(a);
            }
            
        }

        return ans;
    }
};