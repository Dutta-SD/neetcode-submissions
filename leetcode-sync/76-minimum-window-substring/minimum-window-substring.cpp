class Solution {
private:
    bool isContained(std::unordered_map<char, int>& a,
                     std::unordered_map<char, int>& b) {
        for (const auto& [ch, count_a] : a) {
            auto it = b.find(ch);
            // If the character is missing from b, or b has fewer than a
            if (it == b.end() || it->second < count_a) {
                return false;
            }
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";

        pair<int, int> window = {0, INT_MAX};
        int S = s.size();
        int T = t.size();

        unordered_map<char, int> countsT, countsS;

        for (char c : t) {
            countsT[c]++;
        }

        for (int i = 0; i < T; i++) {
            countsS[s[i]]++;
        }

        if (countsT == countsS)
            return s.substr(0, T);

        int l = 0, r = T - 1;

        while (r < S - 1) {
            r++;

            countsS[s[r]]++;
            while (l <= r - T + 1 && isContained(countsT, countsS)) {
                if (r - l + 1 < window.second) {
                    window = {l, r - l + 1};
                }
                countsS[s[l]]--;
                l++;
            }
        }

        return window.second == INT_MAX ? ""
                                        : s.substr(window.first, window.second);
    }
};