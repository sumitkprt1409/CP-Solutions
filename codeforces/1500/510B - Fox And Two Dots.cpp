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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool cycle = false;

void dfs(int n, int m, int x, int y, int X, int Y, vector<string> &board, char color, vector<vector<int>> &visited){
    if(x < 0 || y < 0 || x >= n || y >= m){
        return;
    }

    

    if(board[x][y] != color){
        return;
    }

    if(visited[x][y]){
        cycle = true;
        return;
    }
    visited[x][y] = 1;

    for(int k=0; k<4; k++){
        int new_x = x + dx[k];
        int new_y = y + dy[k];

        if(new_x == X && new_y == Y){
            continue;
        }

        dfs(n, m, new_x, new_y, x, y, board, color, visited);
    }
}

void solve(){
    int n, m;
    cin>>n>>m;
    vector<string> board(n);
    for(int i=0; i<n; i++){
        cin>>board[i];
    }

    vector<vector<int>> visited(n, vector<int> (m, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j]){
                dfs(n, m, i, j, -1, -1, board, board[i][j], visited);
            }
        }
    }

    if(cycle){
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