class Solution {
public:
    int addDigits(int num) {
        int ans = 0;
        while(num >= 10){
            int sum = 0;
            int temp = num;
            while(temp > 0){
                sum += temp%10;
                temp /= 10;
            }
            ans++;
            num = sum;
        }


        return num;
    }
};