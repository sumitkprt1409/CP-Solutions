class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int n = s.size();
        pair<char, int> arr[7] = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        ans = 0;
        int prev = 0;
        for(int i=n-1; i>=0; i--){
            int num = 0;
            for (int j = 0; j < 7; j++) {
                if (s[i] == arr[j].first) {
                    num = arr[j].second;
                    break;
                }
            }
            if(num >= prev){
                ans += num;
            }
            else{
                ans -= num;
            }
            prev = num;
        }
        return ans;
    }
};