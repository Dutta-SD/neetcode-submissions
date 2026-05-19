class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        unordered_map<char, int> counts, s_counts;

        for (char c : s1) {
            counts[c]++;
        }

        int l = -s1.size();
        int r = -1;

        while (r + 1 < s2.size()) {
            r++;
            l++;
            s_counts[s2[r]]++;
            if (l >= 1) {
                s_counts[s2[l - 1]]--;
                if (s_counts[s2[l - 1]] == 0) {
                    s_counts.erase(s2[l - 1]);
                }
            }

            if (s_counts == counts)
                return true;
        }

        return false;
    }
};