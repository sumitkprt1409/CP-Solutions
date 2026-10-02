class Solution {
public:
    vector<string> ans;
    void Helper(int n, int m, string curr){
        if(n == 0 && m == 0){
            ans.push_back(curr);
        }
        if(n < 0 || m < 0){
            return;
        }
        

        //take (
        Helper(n-1, m, curr+'(');

        //take )
        if(m > n){
            Helper(n, m-1, curr+')');
        }
        
    }

    vector<string> generateParenthesis(int n) {
        string s;
        Helper(n, n, s);
        return ans;
    }
};