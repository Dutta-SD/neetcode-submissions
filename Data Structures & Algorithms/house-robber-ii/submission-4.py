class Solution:
    def rob(self, nums: List[int]) -> int:
        def hr(nums: List[int]) -> int:
            dp = [0] * len(nums)
            dp[0] = nums[0]
            dp[1] = max(nums[0], nums[1])

            for i in range(2, len(nums)):
                dp[i] = max(dp[i - 1], nums[i] + dp[i - 2])

            return dp[-1]

        if len(nums) == 0:
            return 0
        if len(nums) < 4:
            return max(nums)

        return max(hr(nums[1:]), hr(nums[:-1]))
