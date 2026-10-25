class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            vector<int> arr1(31, 0), arr2(31, 0);

            vector<int> a(26, 0);
            int A = 0;

            for (int j = i; j >= 0; j--) {
                int idx = s[j] - 'a';

                if (a[idx] == 0) {
                    A++;
                    a[idx] = 1;
                }

                arr1[A]++;
            }

            vector<int> b(26, 0);
            int B = 0;

            for (int j = i + 1; j < n; j++) {
                int idx = s[j] - 'a';

                if (b[idx] == 0) {
                    B++;
                    b[idx] = 1;
                }

                arr2[B]++;
            }

            for (int j = 0; j < 31; j++) {
                ans += arr1[j] * arr2[j];
            }
        }

        return ans;
    }
};