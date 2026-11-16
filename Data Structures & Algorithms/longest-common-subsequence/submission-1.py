class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        M = len(text1)
        N = len(text2)

        dp = [[0] * (M + 1) for _ in range(N + 1)]

        for i in range(1, N + 1):
            for j in range(1, M + 1):
                if text2[i - 1] == text1[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])

        return dp[-1][-1]
