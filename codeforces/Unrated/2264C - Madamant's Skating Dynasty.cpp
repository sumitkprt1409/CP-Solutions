#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 998244353;

ll modPow(ll a, ll b) {
    ll ans = 1;

    while (b) {
        if (b & 1)
            ans = ans * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);

    for (auto &x : a)
        cin >> x;

    sort(a.rbegin(), a.rend());

    // (n-1)!
    ll fact = 1;

    for (int i = 1; i <= n - 1; i++) {
        fact = fact * i % MOD;
    }

    ll prefix = a[0] % MOD;
    ll ans = 0;

    for (int i = 1; i < n; i++) {

        // Sum of:
        // (a[0] - a[i]) + ... + (a[i-1] - a[i])
        ll edgeSum =
            (prefix - (i * (a[i] % MOD)) % MOD + MOD) % MOD;

        // (n-1)! / i
        ll ways = fact * modPow(i, MOD - 2) % MOD;

        ans = (ans + edgeSum * ways) % MOD;

        prefix = (prefix + a[i]) % MOD;
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

    return 0;
}