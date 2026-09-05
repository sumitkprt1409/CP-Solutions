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

int height[N];
int depth[N];

vector<vector<int>> edges(N);
int par[N][M];

void dfs(int curr, int parent) {

    height[curr] = height[parent] + 1;
    
    // Parent of curr
    par[curr][0] = parent;

    // Binary lifting
    for (int i = 1; i < M; i++) {
        par[curr][i] = par[par[curr][i - 1]][i - 1];
    }

    for (auto x : edges[curr]) {
        if (x != parent) {
            dfs(x, curr);
        }
    }
}

int LCS(int a, int b) {

    if (a == b) {
        return a;
    }

    if (height[a] < height[b]) {
        swap(a, b);
    }

    int diff = height[a] - height[b];

    for (int i = M - 1; i >= 0; i--) {
        if ((1 << i) & diff) {
            a = par[a][i];
        }
    }

    if (a == b) {
        return a;
    }

    for (int i = M - 1; i >= 0; i--) {
        if (par[a][i] != par[b][i]) {
            a = par[a][i];
            b = par[b][i];
        }
    }

    return par[a][0];
}

void solve() {

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        edges[a].pb(b);
        edges[b].pb(a);
    }

    height[0] = -1;

    dfs(1, 0);

    while (q--) {

        int a, b;
        cin >> a >> b;

        int lca = LCS(a, b);

        int ans = height[a] + height[b] - 2 * height[lca];

        cout << ans << endl;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}