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
    ll n, k, x;
    cin>>n>>k>>x;

    vector<ll> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<ll> gaps;

    int num = 1;
    for(int i=0; i<n-1; i++){
        if(arr[i+1] - arr[i] <= x){
            continue;
        }
        else{
            gaps.pb(arr[i+1] - arr[i]);
        }
        // else{
        //     int cnt = ceil((arr[i+1] - arr[i])/x) - 1;
        //     if(cnt <= k){
        //         k -= cnt;
        //     }
        //     else{
        //         num++;
        //     }

        // }
    }

    sort(gaps.begin(), gaps.end());
    int group = gaps.size() + 1;

    for(int i=0; i<gaps.size(); i++){
        ll cnt = (gaps[i] + x - 1)/x - 1;
        if(cnt <= k){
            k -= cnt;
            group--;
        }

    }

    cout<<group<<endl;
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