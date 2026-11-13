class Solution:
    def reverseBits(self, n: int) -> int:
        l = 31
        r = 0
        res = 0
        while r < 32:
            if n & 1:
                # last digit 1:
                res += 1 << l
            l -= 1
            n >>= 1
            r += 1

        return res
