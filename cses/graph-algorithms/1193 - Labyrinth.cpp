#include <bits/stdc++.h>
using namespace std;

// Types
#define ll long long
#define ld long double
#define endl '\n'

// Constants
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

// Shortcuts
#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int x1, y1, x2, y2;

    // Find A and B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                x1 = i;
                y1 = j;
            }

            if (grid[i][j] == 'B') {
                x2 = i;
                y2 = j;
            }
        }
    }

    queue<pair<int, int>> q;

    vector<vector<int>> visited(n, vector<int>(m, 0));

    // previous[x][y] = direction used to reach (x,y)
    vector<vector<int>> previous(n, vector<int>(m, -1));

    q.push({x1, y1});
    visited[x1][y1] = 1;

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    char dir[] = {'L', 'R', 'U', 'D'};

    // BFS
    while (!q.empty()) {

        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int k = 0; k < 4; k++) {

            // Don't modify x and y
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < m &&
                grid[nx][ny] != '#' &&
                !visited[nx][ny]) {

                visited[nx][ny] = 1;

                // Store direction used to reach this cell
                previous[nx][ny] = k;

                q.push({nx, ny});
            }
        }
    }

    // No path
    if (!visited[x2][y2]) {
        cout << "NO" << endl;
        return;
    }

    // Path exists
    cout << "YES" << endl;

    string ans = "";

    // Backtrack from B to A
    while (x2 != x1 || y2 != y1) {

        int p = previous[x2][y2];

        ans += dir[p];

        // Move backwards
        x2 -= dx[p];
        y2 -= dy[p];
    }

    // We reconstructed B -> A, so reverse it
    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;

    while (t--) {
        solve();
    }

    return 0;
}