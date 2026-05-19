class Solution {
public:
    vector<int> evenOddBit(int n) {
        int odd_mask = (pow(2, 12) - 1) / 3 * 2;

        return {__builtin_popcount((odd_mask >> 1) & n),
                __builtin_popcount(odd_mask & n)};
    }
};