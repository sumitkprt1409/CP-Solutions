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
    
    ll sum = 0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    vector<ll> prefix(n);
    prefix[0] = arr[0];
    
    bool ans = true;
    
    for(int i=1; i<n; i++){
        prefix[i] = prefix[i-1] + arr[i];
        if(prefix[i] < 0){
            ans = false;
        }
    }
    
    if(ans && arr[0] > 0){
        cout<<"YES"<<endl;
        return;
    }
    
    
    for(int i=-1; i<n; i++){
        ans = true;
        sum = 0;
        for(int j=0; j<n; j++){
            int rem = arr[i];
            
            if(i == j){
                continue;
            }
            
            sum += arr[j];
            
            if(sum < 0){
                ans = false;
                break;
            }
        }
        
        if(ans){
            cout<<"YES"<<endl;
            return;
        }
    }
    
    
    cout<<"NO"<<endl;
    
    
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