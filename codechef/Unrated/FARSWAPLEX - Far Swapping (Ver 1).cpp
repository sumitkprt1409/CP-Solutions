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
    
    // if(n <= 3){
    //     for(int i=0; i<n; i++){
    //         cout<<arr[i]<<" ";
    //     }
    //     cout<<endl;
    //     return;
    // }
    
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int j = 0; j < n - 1; j++) {

            if (arr[j] - arr[j + 1] > 1) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
    }

    
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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