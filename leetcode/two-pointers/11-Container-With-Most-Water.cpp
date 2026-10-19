class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int i = 0, j = n-1;

        while(i < j){
            int x = j-i;
            int mini = min(height[i], height[j]);
            ans = max(ans, mini*x);

            if(height[i] <= height[j]){
                i++;
            }
            else{
                j--;
            }
        }

        return ans;



    }
};