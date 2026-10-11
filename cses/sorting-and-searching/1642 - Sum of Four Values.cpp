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
    ll x;
    cin>>n>>x;
    vector<ll> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    map<ll, pair<int, int>> mpp;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j){
                continue;
            }
            ll sum = arr[i] + arr[j];

            mpp[sum] = {i, j};
        }
    }



    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j){
                continue;
            }

            ll sum = arr[i] + arr[j];

            if(mpp.find(x-sum) != mpp.end()){
                int k = mpp[x-sum].first;
                int l = mpp[x-sum].second;

                if(i != k && i != l && j != k && j != l){
                    cout<<i+1<<" "<<j+1<<" "<<k+1<<" "<<l+1<<endl;
                    return;
                }
            }
        }
    }










    // map<ll, ll> mpp;
    // for(int i=0; i<n; i++){
    //     mpp[arr[i]] = i;
    // }

    // for(int a=0; a<n; a++){
    //     for(int b=0; b<n; b++){
    //         for(int c=0; c<n; c++){
    //            if(a == b || a== c || b == c){
    //             continue;
    //            }

    //            ll sum = arr[a] + arr[b] + arr[c];

    //            if(mpp.find(x-sum) != mpp.end()){
    //                 int idx = mpp[x-sum];

    //                 if(idx != a && idx != b && idx != c){
    //                     cout<<a+1<<" "<<b+1<<" "<<c+1<<" "<<idx+1<<endl;
    //                     return;
    //                 }
    //            }
    //         }
    //     }
    // }

    cout<<"IMPOSSIBLE"<<endl;
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