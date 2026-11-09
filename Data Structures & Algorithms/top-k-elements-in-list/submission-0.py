from collections import defaultdict


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = defaultdict(int)
        for e in nums:
            freq[e] += 1

        res = [(v, k) for (k, v) in freq.items()]
        res.sort(reverse = True)
        return [k for (v, k) in res][:k]
