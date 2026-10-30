
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        if (k == 0) return -1;

        vector<vector<pair<int,int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }

        const long long INF = 1e18;

        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, INF)
        );

        using T = tuple<long long, int, int>;

        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();

            if (d != dist[u][cnt]) continue;

            if (u == n - 1) return (int)d;

            for (auto [v, w] : adj[u]) {

                int newCnt = (labels[u] == labels[v])
                             ? cnt + 1 : 1;

                if (newCnt > k) continue;

                long long nd = d + w;

                if (nd < dist[v][newCnt]) {
                    dist[v][newCnt] = nd;
                    pq.push({nd, v, newCnt});
                }
            }
        }

        return -1;
    }
};
