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

int Helper(vector<int> &price, vector<int> &pages, int n, int x, int idx, vector<vector<int>> &dp){
    if(idx == n){
        return 0;
    }

    if(dp[idx][x] != -1){
        return dp[idx][x];
    }
    //not take
    int not_take = Helper(price, pages, n, x, idx+1, dp);
    
    int take = 0;
    if(price[idx] <= x){
        take += pages[idx] + Helper(price, pages, n, x-price[idx], idx+1, dp);
    }

    return dp[idx][x] = max(not_take, take);
}

void solve(){
    int n, x;
    cin>>n>>x;
    vector<int> price(n), pages(n);
    for(int i=0; i<n; i++){
        cin>>price[i];
    }
    for(int i=0; i<n; i++){
        cin>>pages[i];
    }
    vector<vector<int>> dp(n+1, vector<int> (x+1, 0));

    for(int i=n-1; i>=0; i--){
        for(int p=0; p<=x; p++){
            int nottake = dp[i+1][p];

            int take = 0;

            if(price[i] <= p){
                take = pages[i] + dp[i+1][p-price[i]];
            }

            dp[i][p] = max(take, nottake);
        }
    }


    cout<<dp[0][x]<<endl;




    // int ans = Helper(price, pages, n, x, 0, dp);
    // cout<<ans<<endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}