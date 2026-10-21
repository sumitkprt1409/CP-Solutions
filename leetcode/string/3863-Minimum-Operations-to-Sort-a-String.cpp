
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        string a = s;
        sort(a.begin(), a.end());

        if (s == a) return 0;

        if (n == 2) return -1;

        char mini = a[0];
        char maxi = a[n - 1];

        int c = 0;
        int b = 0;

        for(int i=0; i<n; i++){
            if(s[i] == mini){
                c++;
            }
            if(s[i] == maxi){
                b++;
            }
        }

        if (s[0] == mini || s[n - 1] == maxi){
            return 1;
        }
        if (s[0] == maxi && s[n - 1] == mini && c == 1 && b == 1){
            return 3;
        }
        return 2;
    }
};
