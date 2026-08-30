class Solution {
public:
    string intToRoman(int num) {

        vector<pair<int, string>> roman = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        string ans = "";

        for (auto [value, symbol] : roman) {
            while (num >= value) {
                ans += symbol;
                num -= value;
            }
        }

        return ans;











        // string ans = "";
        // // map<int, char> mpp;
        // // mpp = ({1, I}, {5, V}, {10, X}, {50, L}, {C, 100}, {D, 500}, {M, 1000});

        // int temp = num;
        // int i=0;
        // if(num == 10){
        //     return "X";
        // }
        // while(temp > 0){
        //     int n = temp%10;
        //     int j = i;
        //     while(j > 0){
        //         n *= 10;
        //         j--;
        //     }

        //     if(i == 0){
        //         if(n == 0){
        //             continue;
        //         }
        //         else if(n <= 8 && n >= 1){
        //             if(n == 5){
        //                 ans += "V";
        //             }
        //             else if(n == 1){
        //                 ans += "I";
        //             }
        //             else if(n == 2){
        //                 ans += "II";
        //             }
        //             else if(n == 3){
        //                 ans += "III";
        //             }
        //             else if(n == 4){
        //                 ans += "VI";
        //             }
        //             else if(n == 6){
        //                 ans += "IV";
        //             }
        //             else if(n == 7){
        //                 ans += "IIV";
        //             }
        //             else{
        //                 ans += "IIIV";
        //             }
        //         }
        //         else{
        //             ans += "XI";
        //         }
        //     }
        //     else if(i == 1){
        //         if(n == 0){
        //             continue;
        //         }
        //         else if(n <= 80 && n >= 10){
        //             if(n == 50){
        //                 ans += "L";
        //             }
        //             else if(n == 10){
        //                 ans += "X";
        //             }
        //             else if(n == 20){
        //                 ans += "XX";
        //             }
        //             else if(n == 30){
        //                 ans += "XXX";
        //             }
        //             else if(n == 40){
        //                 ans += "LX";
        //             }
        //             else if(n == 60){
        //                 ans += "XL";
        //             }
        //             else if(n == 70){
        //                 ans += "XXL";
        //             }
        //             else{
        //                 ans += "XXXL";
        //             }
        //         }
        //         else{
        //             ans += "CX";
        //         }
        //     }
        //     else if(i == 2){
        //         if(n == 0){
        //             continue;
        //         }
        //         else if(n <= 800 && n >= 100){
        //             if(n == 500){
        //                 ans += "D";
        //             }
        //             else if(n == 100){
        //                 ans += "C";
        //             }
        //             else if(n == 200){
        //                 ans += "CC";
        //             }
        //             else if(n == 300){
        //                 ans += "CCC";
        //             }
        //             else if(n == 400){
        //                 ans += "DC";
        //             }
        //             else if(n == 600){
        //                 ans += "CD";
        //             }
        //             else if(n == 700){
        //                 ans += "CCD";
        //             }
        //             else{
        //                 ans += "CCCD";
        //             }
        //         }
        //         else{
        //             ans += "MC";
        //         }
        //     }
        //     else if(i == 3){
        //         if(n == 0){
        //             continue;
        //         }
        //         else if(n <= 8000 && n >= 1000){
        //             if(n == 5000){
        //                 ans += "MMMMM";
        //             }
        //             else if(n == 1000){
        //                 ans += "M";
        //             }
        //             else if(n == 2000){
        //                 ans += "MMM";
        //             }
        //             else if(n == 3000){
        //                 ans += "MMM";
        //             }
        //             else if(n == 4000){
        //                 ans += "MMMM";
        //             }
        //         }
        //         else{
        //             continue;
        //         }
        //     }
        //     i++;
        //     temp /= 10;

        // }

        // reverse(ans.begin(), ans.end());
        // return ans;
    }
};