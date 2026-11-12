import heapq as h


class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        points_tuple = [(x * x + y * y, x, y) for (x, y) in points]
        h.heapify(points_tuple)

        return [[x, y] for (_, x, y) in h.nsmallest(k, points_tuple)]

