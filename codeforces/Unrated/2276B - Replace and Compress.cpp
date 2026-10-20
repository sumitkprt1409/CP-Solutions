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
    string s;
    cin >> s;

    int n = s.size();
    int ans = 1;
    int a = 0;
    int b = 0;

    for (int i = 1; i < n - 1; i++) {
        if(s[i-1] == s[i] && s[i] == s[i+1]){
            a = 1;
        }
        if(s[i-1] != s[i] && s[i] != s[i+1]){
            b = 1;
        }
    }
    cout << ans + a + b<< '\n';


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