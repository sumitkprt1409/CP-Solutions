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
    int n;
    ll x, y;
    cin>>n>>x>>y;
    vector<ll> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    map<pair<ll, ll>, ll> mpp;
    ll ans = 0;
    for(auto a : arr){
        ll rem1 = a%x;
        ll rem2 = a%y;

        ans += mpp[{(x-rem1)%x, rem2}];
        mpp[{rem1, rem2}]++;
    }

    cout<<ans<<endl;




    // for(int i=0; i<n; i++){
    //     for(int j=i+1; j<n; j++){
    //         if(abs(arr[i]+arr[j])%x == 0 && abs(arr[i]-arr[j])%y == 0){
    //             cnt++;
    //         }
    //     }
    // }
    //cout<<cnt<<endl;
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