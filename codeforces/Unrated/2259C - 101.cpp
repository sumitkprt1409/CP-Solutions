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
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int left = -1, right = -1;

    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            if(left == -1)
                left = i;

            right = i;
        }
    }

    int L = -1, R = -1;
    int best = 0;

    int prev = -1;

    for(int i = 0; i < n; i++){
        if(arr[i] == 1){

            if(prev != -1 && i - prev > best){
                best = i - prev;
                L = prev;
                R = i;
            }

            prev = i;
        }
    }

    if(left != -1){
        for(int i = 0; i < left; i++){
            if(arr[i] == -1){

                if(left - i > best){
                    best = left - i;
                    L = i;
                    R = left;
                }

                break;
            }
        }

        for(int i = n - 1; i > right; i--){
            if(arr[i] == -1){

                if(i - right > best){
                    best = i - right;
                    L = right;
                    R = i;
                }

                break;
            }
        }
    }

    else{
        int l = -1, r = -1;
        for(int i = 0; i < n; i++){
            if(arr[i] == -1){

                if(l == -1)
                    l = i;

                r = i;
            }
        }

        L = l;
        R = r;
    }

    for(int i = 0; i < n; i++){
        if(arr[i] == 1)
            arr[i] = 1;

        else if(i == L || i == R)
            arr[i] = 1;

        else
            arr[i] = 0;
    }

    
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}