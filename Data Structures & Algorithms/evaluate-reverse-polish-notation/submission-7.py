import operator as o
from collections import deque


class Solution:
    operators = {
        "+": o.add,
        "-": o.sub,
        "*": o.mul,
        "/": o.truediv,
    }

    def evalRPN(self, tokens: List[str]) -> int:
        stk = deque()
        for e in tokens:
            if e in self.operators:
                v1 = stk.pop()
                v2 = stk.pop()
                stk.append(self.operators[e](int(v2), int(v1)))
            else:
                stk.append(e)

        return int(stk[-1])
