class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();

        long long j = n - 1;
        while (j >= 0 && s[j] == '1')
            j--;

        long long i = j - 1;
        while (i >= 0 && s[i] == '0')
            i--;

        long long swaps = 0;

        while (i >= 0 && j >= 0) {
            while (i >= 0 && s[i] == '0')
                i--;
            while (j >= 0 && s[j] == '1')
                j--;
            if (i >= 0 && j >= 0 && i < j) {
                swaps += j - i;
                swap(s[i], s[j]);
            } else {
                break;
            }
        }

        return swaps;
    }
};