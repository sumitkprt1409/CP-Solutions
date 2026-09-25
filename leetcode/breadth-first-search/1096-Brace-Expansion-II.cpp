class Solution {
public:

    set<string> parse(string &s, int &i) {

        
        set<string> res;

        while (i < s.size() && s[i] != '}' && s[i] != ',') {

            set<string> curr;

    
            if (islower(s[i])) {
                curr.insert(string(1, s[i]));
                i++;
            }

            else if (s[i] == '{') {
                i++;

                curr = parse(s, i);

                i++;
            }

          
            if (res.empty()) {
                res = curr;
            }
            else {
                set<string> temp;

                for (auto &a : res) {
                    for (auto &b : curr) {
                        temp.insert(a + b);
                    }
                }

                res = temp;
            }
        }

        while (i < s.size() && s[i] == ',') {

            i++; // skip ','

            set<string> curr = parse(s, i);

            res.insert(curr.begin(), curr.end());
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};