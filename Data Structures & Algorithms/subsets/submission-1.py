class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        answer = [[]]
        for num in nums:
            answer += [subset + [num] for subset in answer]
        return answer
