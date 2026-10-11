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
    ll n, x;
    cin>>n>>x;

    vector<pair<ll, ll>> arr(n);

    for(ll i=0; i<n; i++){
        ll x;
        cin>>x;
        arr[i] = {x, i};
    }

    sort(arr.begin(), arr.end());

    for(ll i=0; i<n-2; i++){
        ll target = x - arr[i].first;

        int j = i+1;
        int k = n-1;

        while(j < k){
            ll sum = arr[j].first + arr[k].first;

            if(sum > target){
                k--;
            }
            else if(target > sum){
                j++;
            }
            else{
                cout<<arr[i].second+1<<" "<<arr[j].second+1<<" "<<arr[k].second+1<<endl;
                return;
            }
        }

    }







    // vector<ll> arr(n);
    // for(ll i=0; i<n; i++) cin>>arr[i];

    // map<ll, ll> mpp;
    // for(int i=0; i<n; i++){
    //     mpp[arr[i]] = i;
    // }

    // for(ll i=0; i<n; i++){
    //     for(ll j=0; j<n; j++){
    //         if(i == j){
    //             continue;
    //         }

    //         ll sum = arr[i] + arr[j];

    //         if(mpp.find(x - sum) != mpp.end()){
    //             ll idx = mpp[x - sum];

    //             if(idx != i && idx != j){
    //                 cout<<i+1<<" "<<j+1<<" "<<idx+1<<endl;
    //                 return;
    //             }
    //         }

    //     }
    // }

    cout<<"IMPOSSIBLE"<<endl;

    return;
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