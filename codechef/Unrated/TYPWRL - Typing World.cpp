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

void solve(){
    int n, m;
    cin>>n>>m;
    
    string s, l;
    cin>>s>>l;
    
    for(int i=0; i<n; i++){
        if(l.find(s[i]) != string::npos){
            s[i] = 'L';
        }
        else{
            s[i] = 'R';
        }
    }

    
    int ans = 0;
    int i = 0;
    
    while(i < n){
        int cnt = 0;
        
        while(i < n && s[i] == 'L'){
            cnt++;
            i++;
        }
        
        ans = max(ans, cnt);
        cnt = 0;
        while(i < n && s[i] == 'R'){
            cnt++;
            i++;
        }
        ans = max(ans, cnt);
    }
    cout<<ans<<endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}