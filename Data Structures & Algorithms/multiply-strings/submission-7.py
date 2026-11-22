class Solution:
    mp = {
        "0": 0,
        "1": 1,
        "2": 2,
        "3": 3,
        "4": 4,
        "5": 5,
        "6": 6,
        "7": 7,
        "8": 8,
        "9": 9,
    }

    r_mp = {v: k for (k, v) in mp.items()}

    def to_int(self, x: str) -> int:
        res = 0

        for d in x:
            res = res * 10 + self.mp[d]

        return res

    def to_str(self, x: int) -> str:
        res = ""
        while x:
            d = x % 10
            x //= 10
            res = self.r_mp[d] + res

        return res

    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"
        x = self.to_int(num1) * self.to_int(num2)
        return self.to_str(x)
