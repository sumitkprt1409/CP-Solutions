class Solution {
public:
    bool isRectangleOverlap(vector<int>& r1, vector<int>& r2) {
         int left = max(r1[0], r2[0]);
        int right = min(r1[2], r2[2]);

        int bottom = max(r1[1], r2[1]);
        int top = min(r1[3], r2[3]);

        return left < right && bottom < top;
    }
};