class Solution:
    def _cleanup(self, matrix: List[List[int]], r: int, c: int):
        R = len(matrix)
        C = len(matrix[0])

        for ic in range(C):
            matrix[r][ic] = 0

        for ir in range(R):
            matrix[ir][c] = 0

    def setZeroes(self, matrix: List[List[int]]) -> None:
        rows, cols = set(), set()
        R = len(matrix)
        C = len(matrix[0])

        for r in range(R):
            for c in range(C):
                if matrix[r][c] == 0:
                    rows.add(r)
                    cols.add(c)

        for r in range(R):
            for c in range(C):
                if r in rows or c in cols:
                    matrix[r][c] = 0
