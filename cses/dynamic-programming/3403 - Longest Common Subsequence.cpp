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
        int n, m;
        cin>>n>>m;
        vector<int> s1(n), s2(m);
        for(int i=0; i<n; i++){
            cin>>s1[i];
        } 
        for(int i=0; i<m; i++){
            cin>>s2[i];
        }
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){

                if(s1[i] == s2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        int i = 0, j = 0;
        vector<int> ans;

        while(i < n && j < m){
            if(s1[i] == s2[j]){
                ans.push_back(s1[i]);
                i++;
                j++;
            }
            else if(dp[i+1][j] > dp[i][j+1]){
                i++;
            }
            else{
                j++;
            }
        }

        cout<<ans.size()<<endl;

        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<" "; 
        }
        cout<<endl;


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