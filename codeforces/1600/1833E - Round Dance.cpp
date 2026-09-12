#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()

bool hasDegreeOne;
void dfs(int node, vector<vector<int>> &edges,
         vector<int> &visited){

    visited[node] = 1;

    if((int)edges[node].size() == 1){
        hasDegreeOne = true;
    }

    for(auto x : edges[node]){
        if(!visited[x]){
            dfs(x, edges, visited);
        }
    }
}

void solve(){

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    vector<vector<int>> edges(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++){
        int x = arr[i];
        // If i and x mutually remembered each other, that's ONE physical
        // edge reported from both sides — add it only once (when we hit
        // the smaller index), otherwise degree gets inflated.
        if(arr[x] == i && i > x){
            continue;
        }
        edges[x].pb(i);
        edges[i].pb(x);
    }

    int count = 0;
    vector<int> visited(n + 1, 0);
    int pairs = 0;

    for(int i = 1; i <= n; i++){
        hasDegreeOne = false;
        if(!visited[i]){
            count++;
            dfs(i, edges, visited);
        }
        if(hasDegreeOne){
            pairs++;
        }
    }

    int mini = (count - pairs) + (pairs > 0 ? 1 : 0);

    cout << mini << " " << count << endl;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}