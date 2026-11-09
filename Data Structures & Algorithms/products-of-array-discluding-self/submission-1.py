class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)

        if n == 1:
            return nums

        prefix = [0] * n
        suffix = [0] * n
        res = [0] * n

        prefix[0] = nums[0]
        suffix[-1] = nums[-1]

        for i in range(1, n):
            prefix[i] = nums[i] * prefix[i - 1]

        for i in range(n - 2, 0, -1):
            suffix[i] = nums[i] * suffix[i + 1]

        # print(prefix, suffix)

        for i in range(n):
            if i == 0:
                res[0] = suffix[1]
            elif i == n - 1:
                res[n - 1] = prefix[n - 2]
            else:
                res[i] = prefix[i - 1] * suffix[i + 1]

        return res
