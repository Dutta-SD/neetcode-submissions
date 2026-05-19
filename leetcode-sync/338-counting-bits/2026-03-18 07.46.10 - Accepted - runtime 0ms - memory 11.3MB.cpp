class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits;
        for(unsigned long i = 0; i <= n; i++) {
            bits.push_back(__builtin_popcount(i));
        }
        return bits;
    }
};