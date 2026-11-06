class Solution:
    def _is_valid_box(self, board, r, c):
        s = 0
        h_table = [False] * 10
        for i in range(r, r + 3):
            for j in range(c, c + 3):
                e = board[i][j]
                if e.isdigit():
                    e = int(e)
                    if h_table[e]:
                        return False
                    h_table[e] = True
        return True

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            H = [False] * 10
            for j in range(9):
                e = board[i][j]
                if e.isdigit():
                    e = int(e)
                    if H[e]:
                        return False
                    H[e] = True

        for i in range(9):
            H = [False] * 10
            for j in range(9):
                e = board[j][i]
                if e.isdigit():
                    e = int(e)
                    if H[e]:
                        return False
                    H[e] = True

        for i in [0, 3, 6]:
            for j in [0, 3, 6]:
                if not self._is_valid_box(board, i, j):
                    return False

        return True
