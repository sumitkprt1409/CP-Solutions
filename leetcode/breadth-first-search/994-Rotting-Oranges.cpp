class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int no_oranges = 0;
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }

                if(grid[i][j] == 1){
                    no_oranges++;
                }
            }
        }
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while(!q.empty()){
            int size = q.size();
            if(no_oranges == 0){
                break;
            }
           
            for(int i=0; i<size; i++){
                 pair<int, int> arr = q.front();
                    q.pop();
                for(int k=0; k<4; k++){
                    int X = arr.first + dx[k];
                    int Y = arr.second + dy[k];;

                    if(X < n && X >= 0 && Y < m && Y >= 0 && grid[X][Y] == 1){
                        q.push({X, Y});
                        no_oranges--;
                        grid[X][Y] = 2;
                    }
                }
            }
            time++;
        }

        if(no_oranges > 0){
            return -1;
        }

        return time;
    }
};