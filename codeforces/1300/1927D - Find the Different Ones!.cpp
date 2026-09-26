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
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> prefix(n);
    prefix[0] = -1;

    for(int i = 1; i < n; i++){
        if(arr[i] == arr[i-1]){
            prefix[i] = prefix[i-1];
        }
        else{
            prefix[i] = i-1;
        }
    }

    int q;
    cin >> q;

    while(q--){
        int l, r;
        cin >> l >> r;

        l--;
        r--;

        if(prefix[r] >= l){
            cout << prefix[r] + 1 << " " << prefix[r] + 2 << endl;
        }
        else{
            cout << -1 << " " << -1 << endl;
        }
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