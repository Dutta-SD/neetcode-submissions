class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        target = sum(nums)
        if target % 2 != 0:
            return False
        target //= 2
        all_sums = {0}

        for x in nums:
            all_sums.update([v + x for v in all_sums if v + x <= target])

        return target in all_sums
