class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not len(matrix) or not len(matrix[0]):
            return False

        R, C = len(matrix), len(matrix[0])

        def i2c(idx):
            return idx // C, idx % C

        def c2i(i, j):
            return i * C + j

        l = 0
        r = R * C - 1

        while l <= r:
            mid = l + (r - l) // 2
            i, j = i2c(mid)

            if matrix[i][j] == target:
                return True

            if matrix[i][j] < target:
                l = mid + 1
            else:
                r = mid - 1

        return False
