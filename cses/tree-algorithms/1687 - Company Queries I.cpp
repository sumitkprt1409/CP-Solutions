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

const int N = 2e5 + 10;
const int M = 20;

vector<int> adj[N];
int par[N][M];

void dfs(int curr, int parent){
    par[curr][0] = parent;
    for(int j=1; j<M; j++){
        par[curr][j] = par[par[curr][j-1]][j-1];
    }

    for(auto x : adj[curr]){
        if(x != parent){
            dfs(x, curr);
        }
    }
}

int parent(int x, int k){
    for(int i=19; i>=0; i--){
        if((1 << i)&k){
            x = par[x][i];
        }
    }
    return x;
}

void solve(){
    int n, q;
    cin>>n>>q;
    
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        adj[x].pb(i);
    }

    dfs(1, 0);

    while(q--){
        int x, k;
        cin>>x>>k;

        int ans = parent(x, k);
        cout<<(ans == 0 ? -1 : ans)<<endl;
    }
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