class Solution:
    def getSum(self, a: int, b: int) -> int:
        res = 0
        c = 0
        D = 32
        mask = 0xFFFFFFFF


        for i in range(D):
            s = (a & 1) ^ (b & 1) ^ c
            c = (a & 1) & (b & 1) if not c else (a & 1) | (b & 1)
            res |= (s << i)
            a >>= 1
            b >>= 1

        if res > 0x7FFFFFFF:
            res = ~(res ^ mask)


        return res


