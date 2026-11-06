class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [0] * 9
        cols = [0] * 9
        boxes = [0] * 9               # box index = (r//3)*3 + c//3

        for r in range(9):
            for c in range(9):
                ch = board[r][c]
                if ch == '.':
                    continue
                d = 1 << (int(ch) - 1)   # bit for this digit
                b = (r // 3) * 3 + c // 3
                if rows[r] & d or cols[c] & d or boxes[b] & d:
                    return False
                rows[r] |= d
                cols[c] |= d
                boxes[b] |= d
        return True