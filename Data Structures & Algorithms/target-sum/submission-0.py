from collections import defaultdict

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        dp = defaultdict(int)

        def dfs(s, idx):
            if idx >= len(nums):
                dp[(s, idx)] = (s == target)
            if (s, idx) in dp:
                return dp[(s, idx)]

            dp[(s, idx)] += dfs(s + nums[idx], idx + 1)
            dp[(s, idx)] += dfs(s - nums[idx], idx + 1)

            return dp[(s, idx)]

        return dfs(0, 0)
