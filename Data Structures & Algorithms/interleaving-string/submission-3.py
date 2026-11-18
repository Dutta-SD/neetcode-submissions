class Solution:
    def isInterleave(self, s1, s2, s3):
        m, n = len(s1), len(s2)
        if m + n != len(s3):
            return False
        dp = [False] * (n + 1)
        dp[0] = True
        for i in range(m + 1):
            for j in range(n + 1):
                if i > 0:
                    dp[j] = dp[j] and s1[i-1] == s3[i+j-1]
                if j > 0:
                    dp[j] = dp[j] or (dp[j-1] and s2[j-1] == s3[i+j-1])
        return dp[n]