"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""


class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        iv = defaultdict(int)
        count = 0

        for i in intervals:
            iv[i.start] += 1
            iv[i.end] -= 1

        for i in sorted(iv.items()):
            count += i[1]
            if count > 1:
                return False

        return True
