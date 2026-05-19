class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto f = lower_bound(nums.begin(), nums.end(), target);
        
        // If target is not found, return [-1, -1] immediately
        if (f == nums.end() || *f != target) {
            return {-1, -1};
        }
        
        // upper_bound points to the first element GREATER than target
        auto e = upper_bound(nums.begin(), nums.end(), target);
        
        int startIdx = distance(nums.begin(), f);
        // The last occurrence is one position before the upper_bound
        int endIdx = distance(nums.begin(), e) - 1;
        
        return {startIdx, endIdx};
    }
};
