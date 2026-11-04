
class Solution {
public:
    using ll = long long;

    multiset<ll> low, high;
    ll lowSum = 0, highSum = 0;

    void add(ll val) {
        if (low.empty() || val <= *low.rbegin()) {
            low.insert(val);
            lowSum += val;
        } else {
            high.insert(val);
            highSum += val;
        }

        balance();
    }

    void remove(ll val) {
        auto it = low.find(val);

        if (it != low.end()) {
            low.erase(it);
            lowSum -= val;
        } else {
            it = high.find(val);
            high.erase(it);
            highSum -= val;
        }

        balance();
    }

    void balance() {
        int total = low.size() + high.size();
        int target = (total + 1) / 2;

        while ((int)low.size() > target) {
            ll val = *low.rbegin();

            low.erase(prev(low.end()));
            lowSum -= val;

            high.insert(val);
            highSum += val;
        }

        while ((int)low.size() < target) {
            ll val = *high.begin();

            high.erase(high.begin());
            highSum -= val;

            low.insert(val);
            lowSum += val;
        }
    }

    ll getCost() {
        ll median = *low.rbegin();

        ll leftCost = median * low.size() - lowSum;
        ll rightCost = highSum - median * high.size();

        return leftCost + rightCost;
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

    
        auto maritovexi = nums;

        vector<ll> cost(n - x + 1);

        low.clear();
        high.clear();
        lowSum = highSum = 0;

        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);

            cost[i - x + 1] = getCost();
        }

        const ll INF = 1e18;

        vector<vector<ll>> dp(
            k + 1, vector<ll>(n + 1, INF)
        );

    
        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {

                dp[j][i] = dp[j][i - 1];

                if (i >= x) {
                    dp[j][i] = min(
                        dp[j][i],
                        dp[j - 1][i - x] + cost[i - x]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
