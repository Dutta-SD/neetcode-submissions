class Solution {
public:
    int minOperations(int n) {
        if (n == 0) return 0; // Handle n=0 case
        int steps = 0;
        long long x = n; // Use long long for safety
        while (x > 0) {
            long long lsb = x & -x;
            long long a = x + lsb;
            long long b = x - lsb;
            
            // Use ll version of popcount
            if (__builtin_popcountll(a) <= __builtin_popcountll(b)) {
                x = a;
            } else {
                x = b;
            }
            steps++;
        }
        return steps;
    }
};
