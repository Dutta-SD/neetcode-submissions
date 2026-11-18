from collections import defaultdict

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        dp = defaultdict(bool)
        if len(s1) + len(s2) != len(s3):
            return False

        def dfs(idx1, idx2, idx3):
            if idx3 == len(s3):
                return idx1 == len(s1) and idx2 == len(s2)

            if (idx1, idx2, idx3) in dp:
                return dp[(idx1, idx2, idx3)]

            if idx1 < len(s1) and s1[idx1] == s3[idx3]:
                dp[(idx1, idx2, idx3)] |= dfs(idx1 + 1, idx2, idx3 + 1)

            if not dp[(idx1, idx2, idx3)] and idx2 < len(s2) and s2[idx2] == s3[idx3]:
                dp[(idx1, idx2, idx3)] |= dfs(idx1, idx2 + 1, idx3 + 1)

            return dp[(idx1, idx2, idx3)]

        return dfs(0, 0, 0)

            
            

            
