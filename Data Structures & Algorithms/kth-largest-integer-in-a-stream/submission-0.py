class KthLargest:
    import heapq

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.nums = nums
        heapq.heapify(self.nums)
        

    def add(self, val: int) -> int:
        heapq.heappush(self.nums, val)
        return heapq.nlargest(self.k, self.nums)[-1]

        
