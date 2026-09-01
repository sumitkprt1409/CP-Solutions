class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0;
        int k = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        // Find S and assign IDs to litter
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') {
                    id[i][j] = k++;
                }
            }
        }

        if (k == 0)
            return 0;

        const int fullMask = (1 << k) - 1;

        /*
            State:
            (row, col, remainingEnergy, mask)

            Encode everything into one integer to reduce
            memory overhead.
        */

        const int MASK = 1 << k;
        const int E = energy + 1;

        // visited[state]
        int totalStates = m * n * E * MASK;

        vector<bool> visited(totalStates, false);

        auto encode = [&](int r, int c, int en, int mask) {
            return (((r * n + c) * E + en) * MASK + mask);
        };

        struct State {
            int r, c, en, mask;
        };

        queue<State> q;

        visited[encode(sr, sc, energy, 0)] = true;
        q.push({sr, sc, energy, 0});

        int moves = 0;

        const int dr[4] = {1, -1, 0, 0};
        const int dc[4] = {0, 0, 1, -1};

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [r, c, en, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == fullMask)
                    return moves;

                // Cannot make another move
                if (en == 0)
                    continue;

                for (int d = 0; d < 4; ++d) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    int newEn = en - 1;
                    int newMask = mask;

                    char cell = classroom[nr][nc];

                    // Collect litter
                    if (cell == 'L') {
                        newMask |= (1 << id[nr][nc]);
                    }

                    // Reset energy
                    if (cell == 'R') {
                        newEn = energy;
                    }

                    int state = encode(
                        nr, nc, newEn, newMask
                    );

                    if (visited[state])
                        continue;

                    visited[state] = true;

                    q.push({
                        nr,
                        nc,
                        newEn,
                        newMask
                    });
                }
            }

            ++moves;
        }

        return -1;
    }
};