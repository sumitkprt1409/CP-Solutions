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
    
    vector<int> arr(n);
    int sum = 0;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    
    if(k >= n){
        cout<<sum<<endl;
        return;
    }
    
    sort(arr.begin(), arr.end());
    int ans = 0;
    
    for(int i=n-k-1; i<n; i++){
        ans += arr[i];
        //cout<<arr[i]<<" ";
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