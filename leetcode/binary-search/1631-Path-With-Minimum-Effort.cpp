class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        // {effort, {row, col}}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dx[] = {0, 0, 1, -1};
        int dy[] = {-1, 1, 0, 0};

        while (!pq.empty()) {
            auto [effort, pos] = pq.top();
            pq.pop();

            int i = pos.first;
            int j = pos.second;

            // Already found a better path
            if (effort > dist[i][j])
                continue;

            // Destination
            if (i == n - 1 && j == m - 1)
                return effort;

            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];

                if (x >= 0 && x < n && y >= 0 && y < m) {

                    int edge = abs(heights[i][j] - heights[x][y]);

                    int newEffort = max(effort, edge);

                    if (newEffort < dist[x][y]) {
                        dist[x][y] = newEffort;

                        pq.push({
                            newEffort,
                            {x, y}
                        });
                    }
                }
            }
        }

        return 0;
    }
};