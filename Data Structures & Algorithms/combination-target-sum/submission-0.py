class Solution:
    INT_MAX = float("inf")
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        def dfs(s: int, parent: int) -> list[list[int]]:
            if s < 0:
                return None
            if s == 0:
                return [[]]

            answer = []

            for new_value in nums:
                if new_value <= parent:
                    result: list[list[int]] = dfs(s - new_value, new_value)

                    if result is not None:
                        for r in result:
                            r.append(new_value)

                        answer.extend(result)

            return answer

        return dfs(target, self.INT_MAX)
