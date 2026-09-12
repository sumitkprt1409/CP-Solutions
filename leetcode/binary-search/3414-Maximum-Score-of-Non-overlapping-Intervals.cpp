class Solution {
public:

    struct Node {
        long long score;
        vector<int> ids;
    };

    bool better(const Node& a, const Node& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.ids < b.ids;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // {left, right, weight, original index}
        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        // Sort by left endpoint
        sort(a.begin(), a.end());

        // Store all left endpoints
        vector<long long> left(n);

        for (int i = 0; i < n; i++) {
            left[i] = a[i][0];
        }

        // next[i] = first interval with left > right[i]
        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {

            nxt[i] = upper_bound(
                left.begin(),
                left.end(),
                a[i][1]
            ) - left.begin();
        }

        // dp[i][k]
        // best answer starting from i with k intervals remaining
        vector<vector<Node>> dp(
            n + 1,
            vector<Node>(5)
        );

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // Option 1: don't take i
                dp[i][k] = dp[i + 1][k];

                // Option 2: take i
                Node take;

                take.score = a[i][2];
                take.ids.push_back(a[i][3]);

                if (nxt[i] < n) {

                    take.score += dp[nxt[i]][k - 1].score;

                    for (int x : dp[nxt[i]][k - 1].ids) {
                        take.ids.push_back(x);
                    }
                }

                sort(take.ids.begin(), take.ids.end());

                if (better(take, dp[i][k])) {
                    dp[i][k] = take;
                }
            }
        }

        return dp[0][4].ids;
    }
};