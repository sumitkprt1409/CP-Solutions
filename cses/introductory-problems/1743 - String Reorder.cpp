#include <bits/stdc++.h>
using namespace std;

// Types
#define ll long long
#define ld long double
#define endl '\n'

// Constants
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

// Shortcuts
#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()

bool isPossible(map<char, int> &mpp, char &ch){
    int total = 0;
    char mod = ch;

    for(auto x : mpp){
        char c = x.first;
        int f = x.second;
        if(f > mpp[mod]){
            mod = c;
        }
        total += f;
    }

    return mpp[mod] <= (total + 1)/2 && mpp[ch] <= total/2;
}

void solve(){
    string s;
    cin>>s;
    int n = s.size();
    
    map<char, int> mpp;

    for(int i=0; i<n; i++){
        mpp[s[i]]++;
    }

    char last = '\0';
    string ans;

    for(int j=0; j<n; j++){
        for(int i=0; i<26; i++){
            char ch = i + 'A';

            if(mpp[ch] == 0 || ch == last){
                continue;
            }
            mpp[ch]--;
            if(isPossible(mpp, ch)){
                ans.push_back(ch);
                last = ch;
                break;
            }
            else{
                mpp[ch]++;
            }
        }
    }

    if(ans.size() == n){
        cout<<ans<<endl;
    }
    else{
        cout<<-1<<endl;
    }

    return;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}