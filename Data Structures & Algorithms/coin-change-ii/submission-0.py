class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = defaultdict(int)
        coins.sort()
        total = 0

        def dfs(amount, max_coin_in_chain):
            nonlocal total
            if amount == 0:
                return 1

            if amount < max_coin_in_chain:
                return 0

            if (amount, max_coin_in_chain) in dp:
                return dp[(amount, max_coin_in_chain)]

            for c in coins:
                if amount >= c >= max_coin_in_chain:
                    dp[(amount, max_coin_in_chain)] += dfs(amount - c, c)

            return dp[(amount, max_coin_in_chain)]

        return dfs(amount, -1)
