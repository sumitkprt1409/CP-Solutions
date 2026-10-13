#include <bits/stdc++.h>
using namespace std;

int Helper(vector<int> &arr, int target, int sum, vector<int> &dp) {
    if (sum == target) {
        return 0;
    }

    if (sum > target) {
        return INT_MAX;
    }

    if (dp[sum] != -1) {
        return dp[sum];
    }

    int res = INT_MAX;

    for (int i = 0; i < (int)arr.size(); i++) {
        int curr = Helper(arr, target, sum + arr[i], dp);

        if (curr != INT_MAX) {
            res = min(res, 1 + curr);
        }
    }

    return dp[sum] = res;
}

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(x + 1, INT_MAX);

    dp[0] = 0;

    for (int sum = 1; sum <= x; sum++) {
        for (int i = 0; i < n; i++) {
            if (sum >= arr[i] && dp[sum - arr[i]] != INT_MAX) {
                dp[sum] = min(dp[sum], 1 + dp[sum - arr[i]]);
            }
        }
    }






    // int mini = Helper(arr, x, 0, dp);

    if (dp[x] == INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << dp[x] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}