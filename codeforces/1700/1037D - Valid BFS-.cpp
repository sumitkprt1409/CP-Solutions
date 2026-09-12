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


vector<int> bfs(int n, vector<int> graph, vector<vector<int>> &edges){

    queue<int> q;
    q.push(1);

    vector<int> visited(n + 1, 0);
    visited[1] = 1;

    while(!q.empty()){

        int node = q.front();
        q.pop();

        graph.pb(node);

        for(int x : edges[node]){

            if(!visited[x]){

                visited[x] = 1;
                q.push(x);
            }
        }
    }

    return graph;
}


void solve(){

    int n;
    cin >> n;

    vector<vector<int>> edges(n + 1);
    vector<int> tree(n);

    for(int i = 0; i < n - 1; i++){

        int x, y;
        cin >> x >> y;

        edges[x].pb(y);
        edges[y].pb(x);
    }

    vector<int> order(n + 1);

    for(int i = 0; i < n; i++){

        cin >> tree[i];

        order[tree[i]] = i;
    }

    if(tree[0] != 1){
        cout << "No" << endl;
        return;
    }

    for(int i = 1; i <= n; i++){

        sort(edges[i].begin(), edges[i].end(),
             [&](int a, int b){

                return order[a] < order[b];
             });
    }

    vector<int> graph;

    graph = bfs(n, graph, edges);

    if(graph == tree){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }

    return 0;
}