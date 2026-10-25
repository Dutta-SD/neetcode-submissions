class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = max(nums)
        minP, maxP = 1, 1

        for num in nums:
            t_max = num * maxP
            maxP = max(t_max, minP * num, num)
            minP = min(t_max, minP * num, num)
            res = max(res, maxP)

        return res
