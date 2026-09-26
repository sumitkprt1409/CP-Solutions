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
    int n;
    cin>>n;
    string s;
    cin>>s;

    if(s[0] == '1'){
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                cnt++;
            }
        }

        cout<<cnt<<endl;
        return;
    }
    else{
        vector<int> one(n), zero(n);
        int cnt_0 = 0;
        for(int i=n-1; i>=0; i--){
            zero[i] = cnt_0;
            if(s[i] == '0'){
                cnt_0++;
            }
        }

        int cnt_1 = 0;
        for(int i=0; i<n; i++){
            one[i] = cnt_1;
            if(s[i] == '1'){
                cnt_1++;
            }
        }
        
       
        int ans = min(cnt_1, cnt_0);

        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                ans = min(ans, one[i]+zero[i]);
            }
        }

        cout<<ans<<endl;


    }
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