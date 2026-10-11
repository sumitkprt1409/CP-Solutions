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

int dist(int a, int b){
    return (a==b) ? 2 : 1;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n), b(n);

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    for(int i=0; i<n; i++){
        cin>>b[i];
    }

    ll cur = dist(a[n - 1], b[n - 1]);

    for (int i = 0; i < n - 1; i++) {
        cur += dist(a[i], b[i + 1]);
        cur += dist(a[i + 1], b[i]);
    }

    ll thegrilla = cur;

    for (int i = 0; i < n - 1; i++) {
        cur += dist(a[i], b[i]);
        cur -= dist(a[i], b[i + 1]);

        thegrilla = max(thegrilla, cur);
    }

    cout << thegrilla << '\n';
   
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