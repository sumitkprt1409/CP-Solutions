class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> mpp;
        int n = deck.size();

        for(int i=0; i<n; i++){
            mpp[deck[i]]++;
        }

        int mini = 0;
        for(auto it : mpp){
           mini = __gcd(mini, it.second);
        }
        
        return mini >= 2;
    }
};