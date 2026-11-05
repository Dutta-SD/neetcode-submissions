import operator as o
from collections import deque


class Solution:


    def evalRPN(self, tokens: List[str]) -> int:
        operators = {
            "+": o.add,
            "-": o.sub,
            "*": o.mul,
            "/": o.truediv,
        }
        stk = deque()
        for e in tokens:
            if e in operators:
                v1 = stk.pop()
                v2 = stk.pop()
                stk.append(operators[e](int(v2), int(v1)))
            else:
                stk.append(e)

        return int(stk[-1])
