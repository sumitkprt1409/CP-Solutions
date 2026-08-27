#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> parent(n + 1);
    vector<int> c(n + 1);
    vector<bool> hasGoodChild(n + 1, false);

    int root = -1;

    for (int i = 1; i <= n; i++) {
        cin >> parent[i] >> c[i];

        if (parent[i] == -1) {
            root = i;
        }
    }

    // Check whether a vertex has a child with c = 0
    for (int i = 1; i <= n; i++) {
        if (parent[i] != -1 && c[i] == 0) {
            hasGoodChild[parent[i]] = true;
        }
    }

    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        if (i != root && c[i] == 1 && !hasGoodChild[i]) {
            ans.push_back(i);
        }
    }

    if (ans.empty()) {
        cout << -1 << '\n';
    } else {
        for (int x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}