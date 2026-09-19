class Solution {
public:
    bool checkOverlap(int radius, int x, int y, int x1, int y1, int x2, int y2) {

        int X, Y;

        if(x < x1){
            X = x1;
        }
        else if(x2 < x){
            X = x2;
        } 
        else{
            X = x;
        }

        if(y < y1){
            Y = y1;
        }
        else if(y2 < y){
            Y = y2;
        } 
        else{
            Y = y;
        }



        return (sqrt((x-X)*(x-X) + (y-Y)*(y-Y)) <= radius);

    }
};