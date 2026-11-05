import operator as o


class Solution:
    operators = {
        "+": o.add,
        "-": o.sub,
        "*": o.mul,
        "/": o.truediv,
    }

    def act(self, ch: str, v1: str, v2: str) -> int:
        return self.operators[ch](int(v1), int(v2))

    def evalRPN(self, tokens: List[str]) -> int:
        stk = []
        for e in tokens:
            if e in self.operators:
                v1 = stk.pop()
                v2 = stk.pop()
                stk.append(self.act(e, v2, v1))
            else:
                stk.append(e)

        return int(stk[-1])
