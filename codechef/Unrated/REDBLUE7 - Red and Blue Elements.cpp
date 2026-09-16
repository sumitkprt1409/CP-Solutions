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
    cin >> n;

    vector<ll> a(n);

    for (auto &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    vector<ll> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + a[i];
    }

    ll total = prefix[n];
    ll ans = 0;

    for (int cr = 0; cr <= n; cr++) {
        int cb = n - cr;

     
        ll sr = total - prefix[n - cr];

    
        ll sb = prefix[n - cr];

        ll value = sr * cb + sb * cr;

        ans = max(ans, value);
    }

    cout << ans << '\n';
    
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