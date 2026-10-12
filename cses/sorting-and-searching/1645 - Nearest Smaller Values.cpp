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

    for(int i=0; i<n; i++) cin>>arr[i];

    stack<pair<ll, int>> st;
    st.push({0, 0});
    vector<ll> ans(n);

    for(int i=0; i<n; i++){
       while(!st.empty() && st.top().first >= arr[i]){
         st.pop();
       }

       ans[i] = st.top().second;
       st.push({arr[i], i+1});

    }


    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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