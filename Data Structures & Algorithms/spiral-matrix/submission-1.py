class Solution:
    INF = float("inf")
    dirs = (
        (0, 1),  # R
        (1, 0),  # D
        (0, -1),  # L
        (-1, 0),  # U
    )

    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        R, C = len(matrix), len(matrix[0])
        all_elements = [0] * (R * C)
        r, c, d = 0, 0, 0

        for i in range(R * C):
            all_elements[i] = matrix[r][c]
            matrix[r][c] = self.INF
            next_r, next_c = r + self.dirs[d][0], c + self.dirs[d][1]

            if (
                next_r < 0
                or next_r == R
                or next_c < 0
                or next_c == C
                or matrix[next_r][next_c] == self.INF
            ):
                d = (d + 1) % 4
                next_r, next_c = r + self.dirs[d][0], c + self.dirs[d][1]

            r, c = next_r, next_c

        return all_elements
