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
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    if(arr[0] == 1){
        cout<<n+1<<" ";
        for(int i=1; i<=n; i++){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    else if(arr[n-1] == 0){
        for(int i=1; i<=n+1; i++){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    else{
        for(int i=0; i<n-1; i++){
            if(arr[i] == 0 && arr[i+1] == 1){
                for(int j=1; j<=i+1; j++){
                    cout<<j<<" ";
                }
                cout<<n+1<<" ";
                for(int j=i+2; j<=n; j++){
                    cout<<j<<" ";
                }
                cout<<endl;

                return;
            }
           
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