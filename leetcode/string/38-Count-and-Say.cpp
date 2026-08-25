class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        string say = countAndSay(n - 1);
        string ans = "";

        for (int i = 0; i < say.length(); i++) {
            char ch = say[i];
            int cnt = 0;

            while (i < say.length() && say[i] == ch) {
                cnt++;
                i++;
            }

            ans += to_string(cnt) + string(1, ch);
            i--; 
        }

        return ans;
    }
};