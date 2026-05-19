class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp (nums.size() + 2, 0);
        for (int i = 0; i < nums.size(); i++) {
            dp[i+2] = max(nums[i] + dp[i], dp [i+1]);
        }
        return dp.back();
    }
};