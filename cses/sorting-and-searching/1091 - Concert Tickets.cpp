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
    int n, m;
    cin>>n>>m;

    multiset<ll> st;
    for(int i=0; i<n; i++){
        ll x;
        cin>>x;
        st.insert(x);
    }
    
    for(int i=0; i<m; i++){
        ll x;
        cin>>x;

        auto it = st.upper_bound(x);

        if(it == st.begin()){
            cout<<-1<<endl;
        }
        else{
            it--;
            cout<<*it<<endl;
            st.erase(it);
        }
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