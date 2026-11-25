
class Solution {
public:
    using ll = long long;
    using Hash = pair<ll, ll>;

    const ll MOD1 = 1000000007;
    const ll MOD2 = 1000000009;
    const ll BASE = 911382323;

    struct PairHash {
        size_t operator()(const Hash& p) const {
            return p.first ^ (p.second + 0x9e3779b9
                    + (p.first << 6) + (p.first >> 2));
        }
    };

    vector<ll> h1, h2, p1, p2;

    Hash getHash(int l, int r) {
        int len = r - l;

        ll x = (h1[r] - h1[l] * p1[len] % MOD1
                + MOD1) % MOD1;

        ll y = (h2[r] - h2[l] * p2[len] % MOD2
                + MOD2) % MOD2;

        return {x, y};
    }

    bool check(int len, int n) {
        unordered_map<Hash, int, PairHash> freq;
        freq.reserve(n * 2);

        for (int i = 0; i + len <= n; i++) {
            Hash cur = getHash(i, i + len);
            freq[cur]++;
        }

        for (auto& [hash, count] : freq) {
            if (count == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        p1.assign(n + 1, 1);
        p2.assign(n + 1, 1);

        // Precompute prefix hashes and powers
        for (int i = 0; i < n; i++) {
            h1[i + 1] =
                (h1[i] * BASE + nums[i]) % MOD1;

            h2[i + 1] =
                (h2[i] * BASE + nums[i]) % MOD2;

            p1[i + 1] = p1[i] * BASE % MOD1;
            p2[i + 1] = p2[i] * BASE % MOD2;
        }

        // Binary Search
        int low = 1, high = n;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (check(mid, n)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
