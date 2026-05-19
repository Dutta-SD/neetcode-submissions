class Solution {
public:
    int minOperations(int n) {
        // The number of set bits in (n XOR 3n) divided by 2 
        // gives the minimum operations (addition/subtraction).
        return __builtin_popcount(n ^ (3 * n));
    }
};
