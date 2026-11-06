class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if len(intervals) < 2:
            return 0

        intervals.sort(key=lambda x: x[1]) # sort by smallest end time

        # We want a set of the most harmonious intervals
        # The interval with the smallest end time is
        # The most likely to be the least intrusive, so this one 
        # can start the chain.

        end = float("-inf")
        keep = 0
        n = len(intervals)

        for (s, e) in intervals:
            if s >= end:
                keep += 1
                end = e

        return n - keep


