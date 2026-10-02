class Solution {
public:
    bool isThree(int n) {
    int num = sqrt(n);

    if (num * num != n)
        return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }

    return num > 1;
}
};