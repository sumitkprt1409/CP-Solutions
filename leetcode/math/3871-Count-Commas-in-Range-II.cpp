class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        long long num = n;
        if(n < 1000){
            return 0;
        }
       
       for(long long start=1000; start<=n; start *= 1000){
            ans += (n - start + 1);
       }

       


        return ans;;
    }
};