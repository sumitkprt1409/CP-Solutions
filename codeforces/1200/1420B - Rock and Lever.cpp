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
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    ll ans = 0;
    vector<ll> set_bit(31, 0);
    for(int i=0; i<n; i++){
        for(int bit=30; bit>=0; bit--){
            if(arr[i]&(1<<bit)){
                set_bit[bit]++;
                break;
            }
        }
    }

    for(int i=30; i>=0; i--){
        ans += set_bit[i]*(set_bit[i]-1)/2;
        
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