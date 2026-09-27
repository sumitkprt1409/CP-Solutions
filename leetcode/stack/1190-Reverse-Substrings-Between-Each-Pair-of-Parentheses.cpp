class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        string ans = "";
        string curr = "";
        stack<string> st;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push(curr);
                curr = "";
            }
            else if(s[i] == ')'){
                string top = st.top();
                st.pop();
                reverse(curr.begin(), curr.end());
                curr = top + curr;
            }
            else{
                curr += s[i];
            }
        }
        return curr;
    }
};