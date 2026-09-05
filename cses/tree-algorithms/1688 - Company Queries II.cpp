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
int depth[N];

void dfs(int curr, int parent){
    par[curr][0] = parent;
    depth[curr] = depth[parent] + 1;
    for(int i=1; i<M; i++){
        par[curr][i] = par[par[curr][i-1]][i-1];
    }

    for(auto x : adj[curr]){
        if(x != parent){
            dfs(x, curr);
        }
    }
}

int LCA(int a, int b){
    if(a == b){
        return a;
    }
    if(depth[a] < depth[b]){
        swap(a, b);
    }

    int diff = depth[a] - depth[b];
    for(int i=M-1; i>=0; i--){
        if((diff >> i) & 1){
            a = par[a][i];
        }
    }

    for(int i=M-1; i>=0; i--){
        if(par[a][i] != par[b][i]){
            a = par[a][i];
            b = par[b][i];
        }
    }

    return (a != b ? par[a][0] : a);
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
        int a, b;
        cin>>a>>b;

        cout<<LCA(a, b)<<endl;

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