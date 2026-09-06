#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;

vector<vector<int>> adj;
vector<int> subtree;
vector<ll> ans;

// First DFS:
// subtree[u] = size of subtree of u
// ans[1] = sum of distances from node 1
void dfs(int u, int parent, int depth) {

    subtree[u] = 1;

    ans[1] += depth;

    for (int v : adj[u]) {

        if (v == parent)
            continue;

        dfs(v, u, depth + 1);

        subtree[u] += subtree[v];
    }
}

// Second DFS:
// Calculate answer for every node using rerooting
void reroot(int u, int parent) {

    for (int v : adj[u]) {

        if (v == parent)
            continue;

        // Move root from u -> v
        ans[v] = ans[u] + n - 2LL * subtree[v];

        reroot(v, u);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    adj.resize(n + 1);
    subtree.resize(n + 1);
    ans.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {

        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Calculate subtree sizes and ans[1]
    dfs(1, 0, 0);

    // Calculate answers for all nodes
    reroot(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    cout << '\n';

    return 0;
}