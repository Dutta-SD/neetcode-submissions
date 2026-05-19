class Solution {
    void rev(vector<int>& nums, int s, int e) {
        for (int i = 0; i < (e - s) / 2; i++) {
            swap(nums[s + i], nums[e - i - 1]);
        }
    }

public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        rev(nums, 0, n - k);
        rev(nums, n - k, n);
        rev(nums, 0, n);
    }
};