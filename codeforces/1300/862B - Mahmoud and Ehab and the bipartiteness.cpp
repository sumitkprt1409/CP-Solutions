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

int col[2];

void dfs(int curr, int parent, int color, vector<vector<int>> &adj){
    col[color]++;

    for(auto x : adj[curr]){
        if(x != parent){
            dfs(x, curr, color ^ 1, adj);
        }
    }
}

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    // Tree has n - 1 edges
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    col[0] = col[1] = 0;

    dfs(1, 0, 0, adj);

    cout << 1LL * col[0] * col[1] - (n - 1) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }

    return 0;
}