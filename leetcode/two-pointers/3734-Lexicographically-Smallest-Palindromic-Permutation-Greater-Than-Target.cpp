class Solution {
public:

    string buildPalindrome(string half, char mid, int n) {
        string ans = half;

        if (n % 2)
            ans += mid;

        reverse(half.begin(), half.end());
        ans += half;

        return ans;
    }

    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        vector<int> cnt(26, 0);

        for (char ch : s)
            cnt[ch - 'a']++;

        int odd = 0;
        char mid = '#';

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        vector<int> halfCnt(26);

        for (int i = 0; i < 26; i++)
            halfCnt[i] = cnt[i] / 2;

        int halfLen = n / 2;

        string prefix = "";

        for (int i = 0; i < halfLen; i++) {

            int x = target[i] - 'a';

            if (halfCnt[x] > 0) {
                prefix += target[i];
                halfCnt[x]--;
            }
            else {
                break;
            }
        }

        if ((int)prefix.size() == halfLen) {

            string candidate = buildPalindrome(prefix, mid, n);

            if (candidate > target)
                return candidate;
        }


        for (int i = halfLen - 1; i >= 0; i--) {

            vector<int> temp(26);

            for (int k = 0; k < 26; k++)
                temp[k] = cnt[k] / 2;

            bool possible = true;

            for (int j = 0; j < i; j++) {

                int x = target[j] - 'a';

                if (temp[x] == 0) {
                    possible = false;
                    break;
                }

                temp[x]--;
            }

            if (!possible)
                continue;

            int x = target[i] - 'a';

          
            for (int c = x + 1; c < 26; c++) {

                if (temp[c] == 0)
                    continue;

                string half = target.substr(0, i);
                half += char('a' + c);

                temp[c]--;

                for (int k = 0; k < 26; k++) {
                    while (temp[k] > 0) {
                        half += char('a' + k);
                        temp[k]--;
                    }
                }

                return buildPalindrome(half, mid, n);
            }
        }

        return "";
    }
};