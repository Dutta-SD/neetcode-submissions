class Solution {
    // count, index last seen
    vector<pair<int, int>> lastSeenIdxs =
        vector<pair<int, int>>(26, {0, INT_MAX});

public:
    int firstUniqChar(string s) {
        int minIdx = INT_MAX;

        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            lastSeenIdxs[c - 'a'] = {++lastSeenIdxs[c - 'a'].first, i};
        }

        for (auto p : lastSeenIdxs) {
            if (p.first == 1) {
                minIdx = min(minIdx, p.second);
            }
        }

        return minIdx == INT_MAX ? -1 : minIdx;
    }
};