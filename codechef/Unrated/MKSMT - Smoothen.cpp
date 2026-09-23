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

bool check(ll X, vector<int> &a){
        int n = a.size();
        ll S = 0;
        ll prev = -1;

        for (int i = 0; i < n; i++) {
            ll cur = a[i];

            if (cur >= X) {
                S += cur - X;
                cur = X;
            } else {
                ll add = min(S, X - cur);
                cur += add;
                S -= add;
            }

            if (cur < prev)
                return false;

            prev = cur;
        }

        return true;
    }

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    bool flag = true;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
        
        if(i > 0){
            if(arr[i] < arr[i-1]){
                flag = false;
            }
        }
        
    }
    if(flag){
        cout<<-1<<endl;
        return;
    }
    
    ll low = 1;
    ll high = *max_element(arr.begin(), arr.end());
    ll ans = 1;
    
    while(low <= high){
        ll mid = low + (high - low)/2;
        
        if(check(mid, arr)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
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