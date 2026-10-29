class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_val = 1000
        max_val = -1

        for p in prices:
            min_val = min(min_val, p)
            max_val = max(max_val, p - min_val)

        return max_val
