#include <ranges>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> findWordsContaining(std::vector<std::string>& words,
                                         char x) {
        return std::views::iota(0, (int)words.size()) |
               std::views::filter([&](int i) { return words[i].contains(x); }) |
               std::ranges::to<std::vector>();
    }
};
