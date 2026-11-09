class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        c = 1
        n = len(digits)
        for d in range(n - 1, -1, -1):
            s = digits[d] + c
            c = s // 10
            s = s % 10
            digits[d] = s

        if c:
            digits = [c] + digits

        return digits
