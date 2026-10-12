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
    ll n, m;
    ll k;
    cin>>n>>m>>k;

    vector<ll> a(n), b(m);
    for(ll i=0; i<n; i++)  cin>>a[i];

    for(ll i=0; i<m; i++)  cin>>b[i];

    sort(b.begin(), b.end());
    sort(a.begin(), a.end());

    ll i = 0;
    ll j = 0;
    ll cnt = 0;

    while(i < n && j < m){
        if(a[i] < (b[j] - k)){
            i++;
        }
        else if(a[i] > b[j] + k){
            j++;
        }
        else{
            cnt++;
            i++;
            j++;
        }

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