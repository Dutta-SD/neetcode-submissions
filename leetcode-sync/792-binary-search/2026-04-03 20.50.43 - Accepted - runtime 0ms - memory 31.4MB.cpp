class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;

        int mid = lo + (hi-lo) / 2;

        while (hi >= lo) {
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) hi = mid - 1;
            else lo = mid + 1;
            mid = lo + (hi-lo) / 2;
        }

        return -1;
    }
};