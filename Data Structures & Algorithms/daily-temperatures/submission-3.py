from typing import List

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        res = [0] * n
        for i in range(n - 2, -1, -1):
            t = temperatures[i]
            j = i + 1
            while temperatures[j] <= t:
                step = res[j]
                if step == 0:
                    j = i
                    break
                j += step
            res[i] = j - i
        return res