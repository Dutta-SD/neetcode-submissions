class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(128, 0);
        int l = 0;
        int r = 0;
        int wMax = -1;
        int maxFreq = 0;

        for (; r < s.size(); r++) {
            counts[s[r]]++;
            maxFreq = max(maxFreq, counts[s[r]]);

            if ((r - l + 1) - maxFreq > k) {
                counts[s[l]]--;
                l++;
            }

            wMax = max(wMax, (r - l + 1));
        }

        return wMax;
    }
};