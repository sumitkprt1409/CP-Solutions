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

    vector<ll> pre1(n);
    vector<ll> pre2(n);
    pre1[0] = arr[0];
    for(int i=1; i<n; i++){
        pre1[i] = pre1[i-1] + arr[i];
    }

    sort(arr.begin(), arr.end());
    pre2[0] = arr[0];

    for(int i=1; i<n; i++){
        pre2[i] = pre2[i-1] + arr[i];
    }

    int q;
    cin>>q;

    while(q--){
        int type, l, r;
        cin>>type>>l>>r;
        l--, r--;

        if(type == 1){
            ll sum = pre1[r];
            if(l > 0){
                sum -= pre1[l-1];
            }

            cout<<sum<<endl;
        }
        else{
            ll sum = pre2[r];
            if(l > 0){
                sum -= pre2[l-1];
            }

            cout<<sum<<endl;
        }
    }


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