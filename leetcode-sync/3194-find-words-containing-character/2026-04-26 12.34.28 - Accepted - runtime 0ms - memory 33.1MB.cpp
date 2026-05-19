class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> v;
        for (auto [idx, w] : std::ranges::views::enumerate(words)) {
            if (w.contains(x))
                v.push_back(idx);
        }

        return v;
    }
};