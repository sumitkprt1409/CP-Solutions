#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<int> root;
vector<int> sz;

int par(int x) {
    if(x == root[x])
        return x;

    return root[x] = par(root[x]);
}

bool join(int a, int b) {
    a = par(a);
    b = par(b);

    if(a == b)
        return false;

    if(sz[a] > sz[b])
        swap(a, b);

    root[a] = b;
    sz[b] += sz[a];

    return true;
}

void solve() {
    int n, d;
    cin >> n >> d;

    root.resize(n + 1);
    sz.resize(n + 1);

    for(int i = 1; i <= n; i++) {
        root[i] = i;
        sz[i] = 1;
    }

    int extra_edge = 0;

    while(d--) {

        int a, b;
        cin >> a >> b;

        bool merged = join(a, b);

        if(!merged)
            extra_edge++;

        vector<pair<int, int> > temp;

        // Only add component roots
        for(int i = 1; i <= n; i++) {
            if(par(i) == i) {
                temp.push_back(make_pair(sz[i], i));
            }
        }

        // Largest components first
        sort(temp.rbegin(), temp.rend());

        int ans = 0;

        int k = min((int)temp.size(), extra_edge + 1);

        for(int i = 0; i < k; i++) {
            ans += temp[i].first;
        }

        cout << ans - 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}