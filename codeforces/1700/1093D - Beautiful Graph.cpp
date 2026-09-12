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

void dfs(int node, int parent, vector<vector<int>> &edges, vector<int> &color, int &white, int &black, bool &is_bipartite){
    color[node] = color[parent]^1;

    if(color[node] == 0){
        black++;
    }
    else{
        white++;
    }

    for(auto child : edges[node]){
        if(color[child] == -1){
            dfs(child, node, edges, color, white, black, is_bipartite);
        }
        else if(color[child] == color[node]){
            is_bipartite = false;
            return;
        }
    
    }
}

ll modPow(ll a, ll b) {
    ll ans = 1;

    while(b > 0) {

        if(b & 1) {
            ans = ans * a % MOD;
        }

        a = a * a % MOD;
        b >>= 1;
    }

    return ans;
}


void solve(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> edges(n+1);
    vector<int> color(n+1, -1);
    color [0] = 0;
    bool is_bipartite = true;

    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        edges[x].pb(y);
        edges[y].pb(x);
    }

    ll ans = 1;
    for(int i=1; i<=n; i++){
        if(color[i] != -1){
            continue;
        }

        bool is_bipartite = true;
        int white = 0, black = 0;

        dfs(i, 0, edges, color, black, white, is_bipartite);
        
        if(!is_bipartite){
            cout<<0<<endl;
            return;
        }

        ans *= is_bipartite;
        ll temp = (modPow(2, white)%MOD + modPow(2, black)%MOD)%MOD;
        ans *= temp;
        ans %= MOD;

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