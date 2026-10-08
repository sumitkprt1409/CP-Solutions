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
    string s;
    cin>>s;

    stack<int> st;
    vector<int> print(n, 0);

    for(int i=0; i<n; i++){
        if(s[i] == '1'){
            st.push(i);
        }
        else if(s[i] == '2'){
            if(!st.empty()){
                int idx = st.top();
                print[idx] = 1;
                st.pop();
            }
            else{
                print[i] = 1;
            }
        }
        else{
            print[i] = 1;
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(print[i] == 0){
            cnt++;
        }
    }

    cout<<cnt<<endl;

    if(cnt == 0){
        cout<<" "<<endl;
        return;
    }
    for(int i=0; i<n; i++){
        if(print[i] == 0){
            cout<<i+1<<" ";
        }
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