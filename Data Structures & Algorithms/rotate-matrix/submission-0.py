class Solution:
    def _transpose(self, matrix: List[List[int]]) -> None:
        for r in range(len(matrix)):
            for c in range(r + 1, len(matrix[0])):
                matrix[r][c], matrix[c][r] = matrix[c][r], matrix[r][c]

    def _row_reversal(self, matrix: List[List[int]]) -> None:
        for row in matrix:
            row.reverse()

    def rotate(self, matrix: List[List[int]]) -> None:
        self._transpose(matrix)
        self._row_reversal(matrix)
