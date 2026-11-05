class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        mp = {
            ")": "(",
            "]": "[",
            "}": "{"
        }
        for c in s:
            if c in '([{':
                stk.append(c)
            else:
                if len(stk) == 0:
                    return False

                if stk[-1] != mp[c]:
                    return False

                stk.pop()
        
        return len(stk) == 0
        