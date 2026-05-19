class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        int need[26] = {}, have[26] = {}, k = s1.size(), formed = 0;
        for (char c : s1)
            need[c - 'a']++;

        int required = 0;
        for (int i = 0; i < 26; i++)
            if (need[i] > 0)
                required++;

        for (int i = 0; i < k; i++) {
            have[s2[i] - 'a']++;
            if (have[s2[i] - 'a'] == need[s2[i] - 'a'])
                formed++;
        }
        if (formed == required)
            return true;

        for (int r = k; r < (int)s2.size(); r++) {
            char in = s2[r], out = s2[r - k];

            have[in - 'a']++;
            if (have[in - 'a'] == need[in - 'a'])
                formed++;

            have[out - 'a']--;
            if (have[out - 'a'] == need[out - 'a'] - 1)
                formed--;

            if (formed == required)
                return true;
        }
        return false;
    }
};