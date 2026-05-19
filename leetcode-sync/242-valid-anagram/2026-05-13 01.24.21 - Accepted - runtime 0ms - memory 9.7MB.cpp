class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> counts(26, 0);

        if (s.size() != t.size()) return false;

        for (char c : s) {
            counts[c - 'a']++;
        }

        for (char c : t) {
            if (!counts[c - 'a']) {
                return false;
            }
            counts[c - 'a']--;
        }

        return true;
    }
};