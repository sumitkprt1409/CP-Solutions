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
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> pos(n+1);
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
        pos[arr[i]] = i;
    }
   
    vector<ll> dp(1, 1);
    
    for(int i=1; i<n; i++){
        vector<ll> ndp(i + 1);

        if (pos[i] < pos[i + 1]){
            ll sum = 0;

            for (int j = 0; j <= i; j++){
                ndp[j] = sum;
                if (j < i)
                    sum = (sum + dp[j]) % MOD;
            }
        }
        else{
            ll sum = 0;

            for (int j = i; j >= 0; j--) {

                if (j < i)
                    sum = (sum + dp[j]) % MOD;

                ndp[j] = sum;
            }
        }

        dp = ndp;
    }
    
    ll ans = 0;
    for(auto x : dp){
        ans = (ans + x)%MOD;
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