class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        int mid;

        while (low < high) {
            mid = low + (high - low) / 2;

            if (nums[mid] == target) return mid;
            else if (target > nums[mid]) low = std::min(mid + 1, (int) nums.size() - 1);
            else high = std::max(0, mid - 1);
        }
        return target > nums[high] ? high + 1 : high;
    }
};