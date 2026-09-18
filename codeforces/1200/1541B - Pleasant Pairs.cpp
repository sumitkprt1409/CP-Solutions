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
    vector<pair<ll, int>> p(n);

    for(int i=0; i<n; i++){
        cin>>p[i].first;
        p[i].second = i + 1;
    }

    int cnt = 0;

    sort(p.begin(), p.end());

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){

            if(p[i].first*p[j].first >= 2*n){
                break;
            }

            if(p[i].first*p[j].first == p[i].second + p[j].second){
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;
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