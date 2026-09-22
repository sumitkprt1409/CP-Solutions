class Solution {
public:
    static const int MAXK = 5;

    struct Node {
        int prod;
        int cnt[MAXK];

        Node() {
            prod = 1;
            for (int i = 0; i < MAXK; i++)
                cnt[i] = 0;
        }
    };

    int k;
    vector<Node> seg;

    Node mergeNode(const Node &a, const Node &b) {
        Node res;

        res.prod = (1LL * a.prod * b.prod) % k;

        for (int r = 0; r < k; r++) {
            res.cnt[r] = a.cnt[r];
        }

        for (int r = 0; r < k; r++) {
            int nr = (1LL * a.prod * r) % k;
            res.cnt[nr] += b.cnt[r];
        }

        return res;
    }

    Node makeNode(int x) {
        Node res;

        x %= k;

        res.prod = x;
        res.cnt[x] = 1;

        return res;
    }

    void update(int pos, int value, int size) {
        pos += size;
        seg[pos] = makeNode(value);

        for (pos >>= 1; pos >= 1; pos >>= 1) {
            seg[pos] = mergeNode(seg[pos << 1], seg[pos << 1 | 1]);
        }
    }

    Node query(int l, int r, int size) {
        Node left, right;

        l += size;
        r += size;

        while (l <= r) {

            if (l & 1) {
                left = mergeNode(left, seg[l]);
                l++;
            }

            if (!(r & 1)) {
                right = mergeNode(seg[r], right);
                r--;
            }

            l >>= 1;
            r >>= 1;
        }

        return mergeNode(left, right);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int K,
        vector<vector<int>>& queries
    ) {
        k = K;

        int n = nums.size();

        int size = 1;
        while (size < n)
            size <<= 1;

        seg.resize(2 * size);

        for (int i = 0; i < n; i++) {
            seg[size + i] = makeNode(nums[i]);
        }

        for (int i = size - 1; i >= 1; i--) {
            seg[i] = mergeNode(seg[i << 1], seg[i << 1 | 1]);
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(index, value, size);

            Node res = query(start, n - 1, size);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};