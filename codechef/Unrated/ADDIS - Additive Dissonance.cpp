
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
    ll n;
    cin>>n;
    map<ll, ll> mpp;
    for(int i=0; i<n; i++){
        ll x;
        cin>>x;
        mpp[x]++;
    }
    ll freq = 0;

   
    for(auto x : mpp) {
        freq = max(freq, x.second);
    }

    ll sec = 0;

    for(auto x : mpp) {
        if (x.second < freq) {
            sec = max(sec, x.second);
        }
    }
    
    if(freq == 1) {
        cout << 1 << endl;
        return;
    }

    cout<<((freq+1)/2)<<endl;
    
    
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