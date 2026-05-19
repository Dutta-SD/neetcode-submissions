class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> v;
        
        // C++20 range-based algorithm
        ranges::for_each(views::iota(0, (int)words.size()), [&](int i) {
            if (words[i].contains(x)) v.push_back(i);
        });

        return v;
    }
};
