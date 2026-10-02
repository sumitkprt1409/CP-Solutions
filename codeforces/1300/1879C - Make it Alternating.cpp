#include <bits/stdc++.h>
using namespace std;

// Types
#define ll long long
#define ld long double
#define endl '\n'

// Constants
const ll MOD = 998244353;
const ll INF = 1e18;

// Shortcuts
#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()

void solve(){
    string s;
    cin>>s;

    ll ans = 1;
    int n = s.size();
    int curr = 1;
    int len = 1;

    for(int i=0; i<n-1; i++){
        if(s[i] != s[i+1]){
            len++;
            ans = (ans*curr)%MOD;
            curr = 1;
        }
        else{
            curr++;
        }
    }

    ans = ans*curr%MOD;

    for(int i=1; i<=n-len; i++){
        ans = (ans*i)%MOD;
    }

    cout<<n-len<<" "<<ans<<endl;

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