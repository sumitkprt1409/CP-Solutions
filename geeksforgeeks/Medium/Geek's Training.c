class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        
        int prev1 = mat[0][0];
        int prev2 = mat[0][1];
        int prev3 = mat[0][2];
        
        for(int i=1; i<n; i++){
            int A = max(prev2, prev3) + mat[i][0];
            int B = max(prev1, prev3) + mat[i][1];
            int C = max(prev1, prev2) + mat[i][2];
            
            prev1 = A;
            prev2 = B;
            prev3 = C;
        }
        
        return max({prev1, prev2, prev3});
    }
};