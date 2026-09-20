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

    string ans = "";
    for(char ch='a'; ch<='z'; ch++){
        if(s.find(ch) == string::npos){
            ans = ch;
            break;
        }
    }

    for(char c1='a'; c1<='z'; c1++){
        for(char c2='a'; c2<='z'; c2++){
            string temp;
            temp.pb(c1);
            temp.pb(c2);

            if(ans == "" && s.find(temp) == string::npos){
                ans = temp;
                break;
            }
        }
    }

    for(char c1='a'; c1<='z'; c1++){
        for(char c2='a'; c2<='z'; c2++){
            for(char c3='a'; c3<='z'; c3++){
                string temp;
                temp.pb(c1);
                temp.pb(c2);
                temp.pb(c3);

                if(ans == "" && s.find(temp) == string::npos){
                    ans = temp;
                    break;
                }
            }
        }
    }

    cout<<ans<<endl;

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