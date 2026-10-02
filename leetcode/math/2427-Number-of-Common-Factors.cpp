class Solution {
public:
    int commonFactors(int a, int b) {

        int g = gcd(a, b);
        int cnt = 0;

        for(int i = 1; i * i <= g; i++) {

            if(g % i == 0) {
                cnt++;

                if(i != g / i)
                    cnt++;
            }
        }

        return cnt;
        
        // set<int> fact_a, fact_b;

        // for(int i=2; i*i<=a; i++){
        //     if(a%i == 0){
        //         fact_a.insert(i);
        //         fact_a.insert(a/i);
        //     }
        // }

        // for(int i=2; i*i<=b; i++){
        //     if(b%i == 0){
        //         fact_b.insert(i);
        //         fact_b.insert(b/i);
        //     }
        // }
        // int cnt = 1;
        // for(auto x : fact_a){
        //     for(auto y : fact_b){
        //         if(x == y){
        //             cnt++;
        //         }
        //     }
        // }

        // if(a%b == 0){
        //     cnt++;
        // }

        // return cnt;
    }
};