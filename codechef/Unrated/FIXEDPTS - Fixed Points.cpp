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
    
    vector<int> arr(n+1, -1);
    for(int i=1; i<n+1; i++){
        arr[i] = i;
    }
    
    // int num = 0;
    // for(int i=1; i<n+1; i++){
    //     if(arr[i] == i){
    //         num++;
    //     }
    // }
    
    // if(num == k){
    //     cout<<"Yes"<<endl;
    //     return;
    // }
    // cout<<"No"<<endl;
    
    if(n - k == 1){
        cout<<"No"<<endl;
        return;
    }
    
    cout<<"Yes"<<endl;
    
    
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