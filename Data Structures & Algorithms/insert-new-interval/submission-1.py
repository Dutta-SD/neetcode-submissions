class Solution:
    def has_overlap(self, iA: List[int], iB: List[int]) -> bool:
        return max(iA[0], iB[0]) <= min(iA[1], iB[1])

    def merge_intervals(self, iA: List[int], iB: List[int]) -> List[int]:
        return [min(iA[0], iB[0]), max(iA[1], iB[1])]

    def is_before(self, iA: List[int], iB: List[int]) -> bool:
        return iA[1] < iB[0]

    def insert(self, intervals: List[List[int]], new_interval: List[int]) -> List[List[int]]:
        res = []
        idx, n = 0, len(intervals)

        # No overlap - let it in the res
        while idx < n and self.is_before(intervals[idx], new_interval):
            res.append(intervals[idx])
            idx += 1

        # idx has overlap with new_interval
        while idx < n and self.has_overlap(intervals[idx], new_interval):
            new_interval = self.merge_intervals(intervals[idx], new_interval)
            idx += 1

        res.append(new_interval)

        # Add the remaining intervals
        while idx < n:
            res.append(intervals[idx])
            idx += 1

        return res
