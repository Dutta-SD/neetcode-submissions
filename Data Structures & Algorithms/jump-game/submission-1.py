class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        d = n - 1
        for i in range(n - 2, -1, -1):
            if nums[i] + i >= d:
                d = i

        return d == 0
