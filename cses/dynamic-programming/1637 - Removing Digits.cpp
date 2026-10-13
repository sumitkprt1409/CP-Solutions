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

//int mini = INT_MAX;

int Helper(int n, int cnt, vector<int> &dp){
    if(n == 0){
        return 0;
    }
    
    if(n < 0){
        return 0;
    }

    if(dp[n] != -1){
        return dp[n]; 
    }

    vector<int> arr;
    int num = n;
    while(num > 0){
        int digit = num%10;
        if(digit != 0){
            arr.pb(digit);
        }
        num = num/10;
    }

    int mini = INT_MAX;
    for(int digit : arr){
       mini = min(Helper(n-digit, cnt, dp), mini);
    }
    
    return dp[n] = mini+1;
}

void solve(){
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    int ans = Helper(n, 0, dp);

    cout<<ans<<endl;
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