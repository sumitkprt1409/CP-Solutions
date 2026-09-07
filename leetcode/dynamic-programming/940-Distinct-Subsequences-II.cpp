class Solution {
public:
    set<string> st;
    const int MOD = 1e9+7;

    void Helper(int idx, string &s, string a){
        int n = s.size();
        if(idx == n){
            st.insert(a);
        }
        if(idx > n){
            return;
        }

        // take it
        Helper(idx+1, s, a+s[idx]);

        //not take
        Helper(idx+1, s, a);


    }

    int distinctSubseqII(string s) {
        int n = s.size();
        vector<long long> arr(26, 0);
        long long total = 0;
        for(int i=0; i<n; i++){
            int idx = s[i] - 'a';

            int old = total;
            int new_subsequence = (old + 1 - arr[idx] + MOD)%MOD;
            total = (total + new_subsequence)%MOD;
            arr[idx] = (arr[idx] + new_subsequence)%MOD;
        }

        return total;








        // int n = s.size();
        // string a = "";
        // Helper(0, s, a);

        // return st.size()%MOD - 1;



    }
};