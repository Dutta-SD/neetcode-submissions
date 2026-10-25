class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0
        dp = {0: 0}
        for i in coins:
            dp[i] = 1

        MAX_VAL = int(1e10)

        def dfs(amount):
            if amount == 0:
                return 0
            if amount < 0:
                return MAX_VAL
            if amount in dp:
                return dp[amount]

            min_coins = MAX_VAL

            for coin in coins:
                curr_coin_val = dfs(amount - coin)
                min_coins = min(min_coins, curr_coin_val + 1)

            dp[amount] = min_coins
            return min_coins

        return -1 if dfs(amount) >= MAX_VAL else dfs(amount)
