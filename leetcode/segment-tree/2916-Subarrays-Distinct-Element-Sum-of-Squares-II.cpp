class Solution {
public:
    using ll = long long;
    const ll MOD = 1e9 + 7;

    struct Node {
        ll sum = 0;
        ll sqSum = 0;
        ll lazy = 0;
    };

    vector<Node> seg;
    int n;

    void apply(int node, int l, int r, ll x) {
        ll len = r - l + 1;
        ll sum = seg[node].sum;

        seg[node].sqSum =
            (seg[node].sqSum + 2 * x % MOD * sum % MOD
             + len % MOD * x % MOD * x % MOD) % MOD;

        seg[node].sum =
            (sum + len % MOD * x % MOD) % MOD;

        seg[node].lazy = (seg[node].lazy + x) % MOD;
    }

    void push(int node, int l, int r) {
        if (seg[node].lazy == 0 || l == r)
            return;

        int mid = (l + r) / 2;
        ll x = seg[node].lazy;

        apply(node * 2, l, mid, x);
        apply(node * 2 + 1, mid + 1, r, x);

        seg[node].lazy = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr, ll x) {
        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, x);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;

        update(node * 2, l, mid, ql, qr, x);
        update(node * 2 + 1, mid + 1, r, ql, qr, x);

        seg[node].sum =
            (seg[node * 2].sum + seg[node * 2 + 1].sum) % MOD;

        seg[node].sqSum =
            (seg[node * 2].sqSum
             + seg[node * 2 + 1].sqSum) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        seg.assign(4 * n, Node());

        vector<int> last(100001, -1);
        ll ans = 0;

        for (int r = 0; r < n; r++) {
            int prev = last[nums[r]];

            update(1, 0, n - 1, prev + 1, r, 1);

            ans = (ans + seg[1].sqSum) % MOD;

            last[nums[r]] = r;
        }

        return ans;
    }
};