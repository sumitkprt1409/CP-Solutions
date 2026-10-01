class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n%2 != 0){
            return false;
        }
        stack<char> st;

        //( = a, { = b,  [ = c;

        int a = 0, b = 0, c = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }   
            else if(s[i] == ')' && !st.empty()){
                if(st.top() == '('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i] == '}' && !st.empty()){
                if(st.top() == '{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i] == ']' && !st.empty()){
                if(st.top() == '['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }

        if(st.size() > 0){
            return false;
        }
      
        return true;
    }
};