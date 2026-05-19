class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;

        int n = nums.size();
        int wMin = INT_MAX;
        int sum = 0;

        while (r < n) {
            sum += nums[r];
            r++;
            while (sum >= target) {
                wMin = min(wMin, r - l);
                sum -= nums[l++];
            }
        }

        return wMin == INT_MAX ? 0 : wMin;
    }
};