"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

from collections import defaultdict

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        max_val = 0
        count = 0
        iv = defaultdict(int)

        for interval in intervals:
            iv[interval.start] += 1
            iv[interval.end] -= 1

        for item in sorted(iv.items(), key=lambda x: (x[0], x[1])):
            count += item[1]
            max_val = max(count, max_val)

        return max_val






        