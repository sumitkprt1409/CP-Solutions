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
    vector<ll> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int i = 0;
    set<ll> pos, neg;
    ll sum = 0;
    while(i < n){
        if(arr[i] < 0){
            while(i<n && arr[i] < 0){
                pos.insert(arr[i]);
                i++;
            }
        }
        else{
            while(i<n && arr[i] > 0){
                pos.insert(arr[i]);
                i++;
            }
        }

        auto x1 = pos.rbegin();

        sum += *x1;

        pos.clear();

    }

    cout<<sum<<endl;
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