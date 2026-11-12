import random
from typing import List

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        target = len(nums) - k  # index in ascending order
        lo, hi = 0, len(nums) - 1

        while True:
            pivot = nums[random.randint(lo, hi)]
            lt, i, gt = lo, lo, hi

            # 3-way partition: <pivot | ==pivot | >pivot
            while i <= gt:
                if nums[i] < pivot:
                    nums[lt], nums[i] = nums[i], nums[lt]
                    lt += 1
                    i += 1
                elif nums[i] > pivot:
                    nums[i], nums[gt] = nums[gt], nums[i]
                    gt -= 1
                else:
                    i += 1

            if target < lt:
                hi = lt - 1
            elif target > gt:
                lo = gt + 1
            else:
                return nums[target]