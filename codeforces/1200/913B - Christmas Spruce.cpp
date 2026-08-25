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
    vector<vector<int>> edges(n, vector<int>());
    for(int i=0; i<n-1; i++){
        int a;
        cin>>a;
        a--;
        edges[a].pb(i+1);
    }
    bool flag = true;
    for(int i=0; i<n; i++){
        if(edges[i].size() > 0){
            int cnt = 0;
            for(auto x : edges[i]){
                if(edges[x].size() == 0){
                    cnt++;
                }
            }
            if(cnt < 3){
                flag = false;
                break;
            }
        }
    }

    if(flag){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
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