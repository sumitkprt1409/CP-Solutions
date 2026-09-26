#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<ll> dp(n + 1, 0);

    vector<int> spf(n + 1);

    for (int i = 1; i <= n; i++)
        spf[i] = i;

    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }

    for (int x = k + 1; x <= n; x++) {

        int temp = x;

        while (temp > 1) {

            int p = spf[temp];

            dp[x] = min(
                dp[x] == 0 ? LLONG_MAX : dp[x],
                1LL + p * dp[x / p]
            );

            while (temp % p == 0)
                temp /= p;
        }
    }

    ll ans = 0;

    for (int x : a) {
        ans += dp[x];
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}