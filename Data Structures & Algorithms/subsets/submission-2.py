class Solution:
    def l_subsets(self, nums, choices, answer):
        if len(choices) == len(nums):
            answer.append([i for i, v in zip(nums, choices) if v])
            return
        choices.append(True)
        self.l_subsets(nums, choices, answer)
        choices[-1] = False
        self.l_subsets(nums, choices, answer)
        choices.pop()

    def subsets(self, nums: List[int]) -> List[List[int]]:
        answer = []
        choices = []
        self.l_subsets(nums, choices, answer)
        return answer
