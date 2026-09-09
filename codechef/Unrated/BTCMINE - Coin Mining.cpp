
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

int Helper(int x, int y, int k, int day, int profit, vector<int>& dp) {

    if (profit > 0) {
        return day;
    }

    if (day >= dp.size()) {
        return INT_MAX;
    }

    if (dp[day] != -1) {
        return dp[day];
    }

    // Take GPU
    int take = Helper(
        x, y,
        k + 1,
        day + 1,
        profit - x,
        dp
    );

    // Don't take GPU
    int notake = Helper(
        x, y,
        k,
        day + 1,
        profit + y * k * k,
        dp
    );

    return dp[day] = min(take, notake);
}

void solve(){
    ll x, y;
    cin>>x>>y;
    
    ll ans = 1e18;
    
    for(int k=1; k<ans; k++){
        ll earn =  y * k * (k + 1) * (2 * k + 1) / 6;
        ll cost = k*x;
        
        ll profit = earn - cost;
        ll day = k;
        
        if(profit <= 0){
            ll perDay = y * k * k;

            ll extra = (-profit) / perDay + 1;

            day += extra;
        }
        
        ans = min(ans, day);
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