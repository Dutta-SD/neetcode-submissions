class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res = 0
        n = len(nums) + 1

        for x in range(n):
            res = res ^ x

        for x in nums:
            res = res ^ x

        return res
