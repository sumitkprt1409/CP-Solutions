class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int left_sum = 0;
        int right_sum = 0;
        int l = 0, r = 0;
        for(int i=0; i<n/2; i++){
            if(num[i] != '?'){
                left_sum += num[i] - '0';
            }
            else{
                l++;
            }
        }

        for(int i=n/2; i<n; i++){
            if(num[i] != '?'){
                right_sum += num[i] - '0';
            }
            else{
                r++;
            }
        }

        if(l+r == 0){
            if(left_sum == right_sum){
                return false;
            }
            else{
                return true;
            }
        }

        int diff = (left_sum - right_sum);
        int qdiff = l - r;

        if (qdiff % 2 != 0)
            return true;

        // Maximum difference that Bob can compensate
        int possible = (qdiff / 2) * 9;

        // Alice loses only if exact balance is possible
        return diff + possible != 0;




        // if(dif%2 != 0){
        //     return true;
        // }
        // else{
        //     int pair = dif/2;
        //     int max_sum = pair*9;

        //     if(abs(max_sum) == abs(diff_num)){
        //         return false;
        //     }
        //     else{
        //         return true;
        //     }
        // }
    }
};