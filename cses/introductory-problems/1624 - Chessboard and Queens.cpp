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

bool is_Safe(vector<string> &board, int row, int col){
    if(board[row][col] == '*'){
        return false;
    }

    int i = row-1, j = col-1;

    while(i >= 0 && j >= 0){
        if(board[i][j] == 'Q'){
            return false;
        }

        i--;
        j--;
    }
    j = col-1;
    while(j >= 0){
        if(board[row][j] == 'Q'){
            return false;
        }
        j--;
    }

    i=row+1, j = col-1;

    while(i < 8 && j >= 0){
        if(board[i][j] == 'Q'){
            return false;
        }
        i++;
        j--;
    }

    return true;
}


void Helper(vector<string> &board, int col, long long &cnt){
    if(col == 8){
        cnt++;
        return; 
    }

    for(int r=0; r<8; r++){
        if(is_Safe(board, r, col)){
            board[r][col] = 'Q';

            Helper(board, col+1, cnt);

            board[r][col] = '.';
        }
    }
}

void solve(){
    
    vector<string> board(8);
    for(int i=0; i<8; i++){
        cin>>board[i];
    }

    ll cnt = 0;
    Helper(board, 0, cnt);

    cout<<cnt<<endl;

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