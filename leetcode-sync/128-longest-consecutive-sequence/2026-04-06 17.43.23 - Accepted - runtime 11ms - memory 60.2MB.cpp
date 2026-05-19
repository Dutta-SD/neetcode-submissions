class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        int longest = 1, current = 1;
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                current++;
            } else {
                longest = max(longest, current);
                current = 1;
            }
        }
        return max(longest, current);
    }
};
