class Solution {
public:
    void bfs(int i, int j, vector<vector<int>> &image, int &color, int n, int m, vector<vector<int>> &visited){
        queue<pair<int, int>> q;
        q.push({i, j});
        int original = image[i][j];
        visited[i][j] = 1;
        image[i][j] = color;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int k=0; k<4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx>=0 && ny>=0 && nx<n && ny<m && !visited[nx][ny] && original == image[nx][ny]){
                    visited[nx][ny] = 1;
                    image[nx][ny] = color;

                    q.push({nx, ny});
                }
            }

        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        if(image[sr][sc] == color){
            return image;
        }

        vector<vector<int>> visited(n, vector<int> (m, 0));

        bfs(sr, sc, image, color, n, m, visited);

        return image;

    }
};