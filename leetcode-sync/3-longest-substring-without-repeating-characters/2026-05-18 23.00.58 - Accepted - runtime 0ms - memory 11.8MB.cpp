class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int l = 0, r = 0, w = 0;

        for (; r < s.size(); r++) {
            if (lastSeen.count(s[r])) {
                l = max(l, lastSeen[s[r]] + 1);
            }
            lastSeen[s[r]] = r;
            w = max(w, r - l + 1);
        }

        return w;
    }
};