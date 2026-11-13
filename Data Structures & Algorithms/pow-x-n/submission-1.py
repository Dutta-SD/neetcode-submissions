class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1

        neg = False
        if n < 0:
            neg = True
            n = -n
        v = x
        res = 1

        while n:
            if n & 1:
                res *= v
            v *= v
            n = n >> 1

        return res if not neg else 1 / res



        