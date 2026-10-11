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
    ll n, x;
    cin>>n>>x;

    vector<long long> arr(n);
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }

    map<ll, ll> mpp;
    ll cnt = 0;
    ll prefix = 0;
    mpp[0]++;

    for(ll i=0; i<n; i++){
        prefix += arr[i];
        // if(mpp.find(prefix - x) != mpp.end()){
            
        // }
        cnt += mpp[prefix-x];
        mpp[prefix]++;
    }

    cout<<cnt<<endl;
    
    
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