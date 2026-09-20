#include <bits/stdc++.h>
using namespace std;

// Types
#define ll long long
#define ld long double
#define endl '\n'

// Constants
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int N = 1e3+10;

// Shortcuts
#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()

// int Helper(ll a, ll b, vector<vector<int>> &dp){
//     if(a == 0 && b == 0){
//         return 1;
//     }

//     if(a < 0 || b < 0){
//         return 0;
//     }

//     if(dp[a][b] != -1){
//         return dp[a][b];
//     }
    

//     return dp[a][b] = Helper(a-1, b-2, dp) || Helper(a-2, b-1, dp);

// }

void solve(){
    ll a, b;
    cin>>a>>b;

    if((2*a - b)%3 == 0){
        ll y = (2*a - b)/3;

        if((b-y)%2 == 0 && y >= 0){
            ll x = (b-y)/2;
            if(x >= 0){
                cout<<"YES"<<endl;
                return;
            }

           
        }
    }
    cout<<"NO"<<endl;
    
   
    // vector<vector<int>> dp(N, vector<int> (N, -1));

    // if(Helper(a, b, dp)){
    //     cout<<"YES"<<endl;
    // }
    // else{
    //     cout<<"NO"<<endl;
    // }

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