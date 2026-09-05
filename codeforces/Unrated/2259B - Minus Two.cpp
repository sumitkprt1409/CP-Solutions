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

    int even_2 = 0;
    int even_4 = 0;
    int odd = 0;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];

        if(arr[i]&1){
            odd++;
        }

        else if(arr[i] % 4 == 0){
            even_4++;
        }
        else{
            even_2++;
        }
    }

    cout<<max(odd, max(even_4, even_2))<<endl;;

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