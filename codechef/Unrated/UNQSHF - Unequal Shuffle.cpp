
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
    string a, b;
    
    cin>>a>>b;
    
    int x1 = 0, y1 = 0;
    int x2 = 0, y2 = 0;
    for(int i=0; i<n; i++){
        if(a[i] == 'a'){
            x1++;
        }
        else{
            y1++;
        }
        
        if(b[i] == 'a'){
            x2++;
        }
        else{
            y2++;
        }
    }
    
    
    if(x1 == y2 && x2 == y1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
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