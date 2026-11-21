class Solution:
    INT_MAX = 2**31 - 1
    INT_MIN = -(2 ** 31)

    def reverse(self, x: int) -> int:
        neg = x < 0
        if neg:
            x = -x

        # extract digits
        res = 0
        while x:
            d = x % 10
            x //= 10
            res = res + d
            if x: res = res * 10

            if (not neg and res > self.INT_MAX) or (neg and -res < self.INT_MIN):
                return 0

        return -res if neg else res
