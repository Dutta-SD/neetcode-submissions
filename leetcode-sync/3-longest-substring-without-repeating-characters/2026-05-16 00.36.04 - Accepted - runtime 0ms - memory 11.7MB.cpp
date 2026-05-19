class Solution {

public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int start = 0;
        int wMax = 0;

        unordered_map<char, int> lastIdx;

        for (int w = 0; w < n; w++) {
            char currChar = s[w];
            if (lastIdx.count(currChar)) {
                start = max(start, lastIdx[currChar] + 1);
            }
            lastIdx[currChar] = w;
            wMax = max(wMax, w - start + 1);
        }

        return wMax;
    }
};