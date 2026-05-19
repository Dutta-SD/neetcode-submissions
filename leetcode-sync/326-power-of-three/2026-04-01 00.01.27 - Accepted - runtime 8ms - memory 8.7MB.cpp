#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) return false;
        if (n == 1)
            return true;
        return n % 3 == 0 && isPowerOfThree(n / 3);
    }
};