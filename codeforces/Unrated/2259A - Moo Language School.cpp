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
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    int one  = 0;
    int zero = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '1'){
            one++;
        }
        else{
            zero++;
        }
    }

    if(one == n){
        cout<<n/k<<endl;
        return;
    }

    if(zero == n){
        cout<<0<<endl;
        return;
    }
    int ans = 0;
    for(int i=0; i<n; i+=k){
        bool flag = false;
        for(int j=i; j<i+k; j++){
            if(s[j] == '0'){
                flag = true;
            }
        }
        if(flag == false){
            ans++;
        }
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