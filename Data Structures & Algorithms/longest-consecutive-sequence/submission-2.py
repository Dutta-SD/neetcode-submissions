class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        S = set(nums)
        l_max = 0
        for n in S:
            if n - 1 not in S:
                i = n
                curr_max = 0
                while i in S:
                    curr_max += 1
                    i = i + 1

                l_max = max(l_max, curr_max)

        return l_max
