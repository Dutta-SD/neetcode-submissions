class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [1] * len(nums)
        max_val = 1
        for i in range(len(nums)):
            j = i - 1
            while j >= 0:
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], 1 + dp[j])
                    max_val = max(max_val, dp[i])
                j -= 1
        return max_val
