class Solution {
    using ll = long long;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth, base;
    vector<int> bit;
    int timer, LOG;

    void add(int i, int val, int n) {
        for (; i <= n + 1; i += i & -i)
            bit[i] ^= val;
    }

    int sum(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res ^= bit[i];
        return res;
    }

    void rangeUpdate(int l, int r, int val, int n) {
        add(l + 1, val, n);
        add(r + 2, val, n);
    }

    int getMask(int u) {
        return base[u] ^ sum(tin[u] + 1);
    }

    void dfs(int root, int n) {
        // Iterative DFS avoids stack overflow on a chain-shaped tree.
        vector<array<int, 3>> st;
        st.push_back({root, -1, 0});

        while (!st.empty()) {
            auto [u, p, state] = st.back();
            st.pop_back();

            if (state == 1) {
                tout[u] = timer - 1;
                continue;
            }

            tin[u] = timer++;
            base[u] = (p == -1 ? 0 : base[p]) ^
                      (1 << (sChar[u] - 'a'));

            st.push_back({u, p, 1});

            for (int v : adj[u]) {
                if (v == p) continue;
                up[0][v] = u;
                depth[v] = depth[u] + 1;
                st.push_back({v, u, 0});
            }
        }
    }

    char sChar[50001];

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++)
            if (diff & (1 << j))
                u = up[j][u];

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return up[0][u];
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; i++)
            sChar[i] = s[i];

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        up.assign(LOG, vector<int>(n, 0));
        tin.resize(n);
        tout.resize(n);
        depth.assign(n, 0);
        base.assign(n, 0);
        bit.assign(n + 2, 0);
        timer = 0;

        dfs(0, n);

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++)
                up[j][i] = up[j - 1][up[j - 1][i]];
        }

        vector<bool> ans;

        for (auto& q : queries) {
            stringstream ss(q);
            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int delta = (1 << (sChar[u] - 'a')) ^
                            (1 << (c - 'a'));

                rangeUpdate(tin[u], tout[u], delta, n);
                sChar[u] = c;
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);
                int mask = getMask(u) ^ getMask(v) ^
                           (1 << (sChar[w] - 'a'));

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};