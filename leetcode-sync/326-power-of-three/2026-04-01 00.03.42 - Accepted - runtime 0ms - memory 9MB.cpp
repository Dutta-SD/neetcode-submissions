// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class Solution {
public:
    bool isPowerOfThree(int n) { 
        return n > 0 && 1162261467 % n == 0; 
    }
};