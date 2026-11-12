import heapq as h


class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        h.heapify_max(stones)

        while len(stones) > 1:
            x = h.heappop_max(stones)
            y = h.heappop_max(stones)

            if x == y:
                continue
            
            h.heappush_max(stones, x - y)

        return stones[-1] if len(stones) > 0 else 0
