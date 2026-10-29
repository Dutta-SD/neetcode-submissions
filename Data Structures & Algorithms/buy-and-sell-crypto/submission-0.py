class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_val = 1000
        min_vals = []
        max_val = -1

        for p in prices:
            min_val = min(min_val, p)
            min_vals.append(min_val)

        for p, mv in zip(prices, min_vals):
            max_val = max(max_val, p - mv)

        return max_val
