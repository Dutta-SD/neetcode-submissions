class Solution:
    def merge_intervals(self, top: List[int], iB: List[int]) -> List[int]:
        return [min(top[0], iB[0]), max(top[1], iB[1])]

    def has_overlap(self, top: List[int], iB: List[int]) -> bool:
        return max(top[0], iB[0]) <= min(top[1], iB[1])

    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) < 2:
            return intervals

        intervals.sort()

        res = []

        for I in intervals:
            if len(res) == 0:
                res.append(I)
            else:
                top = res[-1]
                if self.has_overlap(top, I):
                    res[-1] = self.merge_intervals(top, I)
                else:
                    res.append(I)

        return res
