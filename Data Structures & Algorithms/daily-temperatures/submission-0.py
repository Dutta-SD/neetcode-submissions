class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stk = []
        res = []
        n = len(temperatures)

        for idx in range(n - 1, -1, -1):
            if len(stk) == 0:
                stk.append((temperatures[idx], idx))
                res.append(0)
            else:
                # consolidate the stack
                while len(stk) > 0 and stk[-1][0] <= temperatures[idx]:
                    stk.pop()

                # next greatest element index
                if len(stk) > 0:
                    _, nge_idx = stk[-1]
                    res.append(nge_idx - idx)
                else:
                    res.append(0)

                stk.append((temperatures[idx], idx))


        return list(reversed(res))
