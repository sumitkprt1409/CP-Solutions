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

void solve(){
    int N, K;
    cin >> N >> K;

    vector<ll> C(N);

    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    ll ans = LLONG_MAX;

    // Try first floodlight
    for (int left = 0; left < N; left++) {

        // Try second floodlight
        for (int right = left + 1; right < N; right++) {

            vector<int> light(N, 0);

            // Light from 'left'
            for (int i = left - K; i <= left + K; i++) {
                if (i >= 0 && i < N) {
                    light[i] = 1;
                }
            }

            // Light from 'right'
            for (int i = right - K; i <= right + K; i++) {
                if (i >= 0 && i < N) {
                    light[i] = 1;
                }
            }

            // Check if every stall is illuminated
            bool possible = true;

            for (int i = 0; i < N; i++) {
                if (light[i] == 0) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                ans = min(ans, C[left] + C[right]);
            }
        }
    }
    
    if(ans == LLONG_MAX){
        cout<<-1<<endl;
        return;
    }
    cout<<ans<<endl;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}