static const int speedup = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        // Sorting + Unique is faster on LeetCode than unordered_set 
        // because of cache locality and avoiding hash overhead.
        sort(nums.begin(), nums.end());
        
        int longest = 1;
        int currentStreak = 1;

        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) { // Skip duplicates
                if (nums[i] == nums[i - 1] + 1) {
                    currentStreak++;
                } else {
                    longest = max(longest, currentStreak);
                    currentStreak = 1;
                }
            }
        }

        return max(longest, currentStreak);
    }
};
