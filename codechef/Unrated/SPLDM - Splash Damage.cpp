
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

// map<vector<int>, int> dp;

// int Helper(vector<int> &arr){
//     int n = arr.size();
//     if(dp.count(arr)){
//         return dp[arr];
//     }

//     int ans = 0;

//     for (int i = 0; i < n; i++) {

//         if(arr[i] <= 0)
//             continue;

//         vector<int> b = arr;

//         b[i] = 0;

//         if (i - 1 >= 0 && b[i - 1] > 0) {
//             b[i - 1]--;
//         }

      
//         if (i + 1 < n && b[i + 1] > 0) {
//             b[i + 1]--;
//         }


//         ans = max(ans, 1 + Helper(b));
//     }

//     return dp[arr] = ans;
// }


void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    // int ans = Helper(arr);
    
    // cout<<ans<<endl;
    
    int neg = -1e9;
    vector<int> dp(2, neg);
    dp[0] = 0;
    
    for(auto x : arr){
        
        int w = 2 - x;
        
        vector<int> new_dp(3, neg);
        
        new_dp[0] = max({dp[0], dp[1], dp[2]});
        
        if(w <= 0){
            new_dp[1] = max(new_dp[1], dp[0] + 1);
        }
        else{
            new_dp[2] = max(new_dp[2], dp[0] + 1);
        }
        
        
        if(dp[1] != neg){

            if(w == 1){
                new_dp[2] = max(new_dp[2], dp[1] + 1);
            }
            else if(w == 0){
                new_dp[1] = max(new_dp[1], dp[1] + 1);
            }
            else{
                new_dp[1] = max(new_dp[1], dp[1] + 1);
            }
        }
        
        if(dp[2] != neg){

            if(w == 1){
               
            }
            else if(w == 0){
                new_dp[2] = max(new_dp[2], dp[2] + 1);
            }
            else{
                new_dp[1] = max(new_dp[1], dp[2] + 1);
            }
        }
        
        dp = new_dp;

    }
    
    cout<<max({dp[0], dp[1], dp[2]})<<endl;
    
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