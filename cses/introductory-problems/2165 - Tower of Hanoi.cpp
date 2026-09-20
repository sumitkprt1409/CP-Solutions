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


void Helper(int n, int start, int end, int middle){
    if(n == 1){
        cout<<start<<" "<<end<<endl;
        return;
    }

    Helper(n-1, start, middle, end);
    cout<<start<<" "<<end<<endl;

    Helper(n-1, middle, end, start);
}

void solve(){
    int n;
    cin>>n;

    cout<<(1 << n) - 1<<endl;
    Helper(n, 1, 3, 2);
    

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