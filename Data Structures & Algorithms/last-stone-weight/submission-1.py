from bisect import insort_left


class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones.sort()

        while len(stones) > 1:
            x = stones.pop()
            y = stones.pop()

            if x == y:
                continue
            
            insort_left(stones, abs(x - y))

        return stones[-1] if len(stones) > 0 else 0
