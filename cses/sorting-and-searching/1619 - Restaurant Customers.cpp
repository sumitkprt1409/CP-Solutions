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
    cin>>n;
    vector<pair<ll, int>> arr;
    for(int i=0; i<n; i++){
        ll x, y;
        cin>>x>>y;

        arr.push_back({x, 1});
        arr.push_back({y, -1});
    }

    sort(arr.begin(), arr.end());

    ll curr = 0;
    ll maxi = 0;
    for(int i=0; i<2*n; i++){
        curr += arr[i].second;
        maxi = max(maxi, curr);
    }
    
    cout<<maxi<<endl;
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