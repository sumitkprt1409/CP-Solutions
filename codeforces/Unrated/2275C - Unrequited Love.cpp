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
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int m = n-4;
    vector<ll> v(m);
    map<ll, ll> mpp;
    ll ans = 0;
    
    for(int i=0; i<m; i++){
        int a = arr[i];
        int b = arr[i+2];
        int c = arr[i+4];

        v[i] = a + b - c;

        mpp[v[i]]++;
        
    }

    for(auto x : mpp){
        ll f = x.second;
        if(f >= 2){
            ans += f*(f-1)/2; 
        }
    }

    for(int i=0; i<m; i++){
        if(i+2 < m &&v[i] == v[i+2]){
            ans--;
        }
        if(i+4 < m && v[i] == v[i+4]){
            ans--;
        }
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