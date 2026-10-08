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
    int X, Y, R;
    cin>>X>>Y>>R;

    int x = X;
    int y1 = Y + R;
    int y2 = Y-R;


    if(sqrt(pow(x-X, 2) + pow(y1-Y, 2)) == R){
        cout<<x<<" "<<y1<<endl;
    }
    else{
        cout<<x<<" "<<y2<<endl;
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