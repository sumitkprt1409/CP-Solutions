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

int dfs(int curr, int parent, vector<vector<int>> &edges, vector<int> &ans){
    if(edges[curr].size() == 0){
        return 1;
    }

    int cnt = 0;
    for(auto child : edges[curr]){
        int temp = dfs(child, curr, edges, ans);
        cnt += temp;
    }

    ans[curr] = cnt;
    return cnt+1;
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> edges(n, vector<int> ());
    for(int i=0; i<n-1; i++){
        int x;
        cin>>x;
        x--;
        edges[x].pb(i+1);
    }
    vector<int> ans(n, 0);
    int a = dfs(0, -1, edges, ans);

    for(int x : ans){
        cout<<x<<" ";
    }
    cout<<endl;
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