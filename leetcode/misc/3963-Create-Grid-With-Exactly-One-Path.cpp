class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m);

        string s = "";
        for(int i=0; i<n; i++){
            s += '.';
        }
        grid[0] = s;

        for(int i=1; i<m; i++){
            s = "";
            for(int j=0; j<n-1; j++){
                s += '#';
            }
            s += ".";
            grid[i] = s;
        }

        return grid;

    }
};