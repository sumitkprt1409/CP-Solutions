#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t; 

	while (t--) {
		int n, m;
		cin >> n >> m; 
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];

		vector<int> rem(m);

	
		for (int i = 0; i < n; i++) {
			rem[v[i] % m]++;
		}

		int ans = 0; 

		for (int i = 0; i < m; i++) {
			int x = rem[i], y = rem[(m - i) % m];

			if ((x == 0) and (y == 0))
				continue;

			int tmp = min(x, y);

			x -= min(tmp + 1, x);
			y -= min(tmp + 1, y);

			ans++;

			ans += (x + y);

			rem[i] = 0;
			rem[(m - i) % m] = 0;
		}

		cout << ans << "\n"; 
	}

	return 0;
}
