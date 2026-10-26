class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [1] * len(nums)
        max_val = 1
        for i in range(len(nums)):
            for j in range(i-1, -1, -1):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], 1 + dp[j])
                    max_val = max(max_val, dp[i])
        return max_val
