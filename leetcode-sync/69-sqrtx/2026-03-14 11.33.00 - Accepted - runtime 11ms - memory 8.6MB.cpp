class Solution {
public:
    int mySqrt(int x) {
        long long unsigned base = 0;
        while (base * base <= x) {
            base++;
        }
        return base - 1;
    }
};