class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int n : numSet) {
            // Only start a sequence if 'n' is the actual start (n-1 doesn't exist)
            if (numSet.find(n - 1) == numSet.end()) {
                int currentNum = n;
                int currentStreak = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                longest = max(longest, currentStreak);
            }
        }
        return longest;
    }
};
