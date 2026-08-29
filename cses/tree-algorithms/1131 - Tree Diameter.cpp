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

void dfs(int curr, int parent, vector<vector<int>> &edges, vector<int> &level){
    if(parent == -1){
        level[curr] = 0;
    }
    else{
        level[curr] = level[parent] + 1;
    }

    for(auto child : edges[curr]){
        if(child != parent){
            dfs(child, curr, edges, level);
        }
    }
}

int farthest(int n, vector<int> dist){
    int far = 0;
    for(int i=0; i<n; i++){
        if(dist[i] > dist[far]){
            far = i;
        }
    }
    return far;
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> edges(n, vector<int> ());

    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }

    vector<int> dist_x(n, -1), dist_y(n, -1);
    int x = 0;

    dfs(x, -1, edges, dist_x);
    
    int y = farthest(n, dist_x);
    dfs(y, -1, edges, dist_y);

    int z = farthest(n, dist_y);
    cout<<dist_y[z]<<endl;

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