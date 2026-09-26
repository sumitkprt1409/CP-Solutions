class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        string ans;
        map<string, string> mpp;
        for(auto x : knowledge){
            mpp[x[0]] = x[1]; 
        }
        int i = 0;
        while(i < n){
            if(s[i] == '('){
                string temp = "";
                int j = i+1;
                while(s[j] != ')'){
                    temp.push_back(s[j]);
                    j++;
                }
                if(mpp.find(temp) != mpp.end()){
                    ans += mpp[temp];
                }
                else{
                    ans.push_back('?');
                }
                
                i = j+1;
            }
            else{
                ans.push_back(s[i]);
                i++;
            }
            
        }

        return ans;

    }
};