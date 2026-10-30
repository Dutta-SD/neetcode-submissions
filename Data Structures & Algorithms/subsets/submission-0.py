class Solution:
    def l_subsets(self, nums, choices, answer):
        if len(choices) == len(nums):
            answer.append([i for i, v in zip(nums, choices) if v])
            return
        self.l_subsets(nums, choices.copy() + [True], answer)
        self.l_subsets(nums, choices.copy() + [False], answer)


    def subsets(self, nums: List[int]) -> List[List[int]]:
        answer = []
        choices = []
        self.l_subsets(nums, choices, answer)
        return answer
        


        