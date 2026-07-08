class Solution {
    private static final char SAFE_MARKER = 'K';
    private static final char O_MARKER = 'O';
    private static final char X_MARKER = 'X';
    private static final int[][] DIRECTIONS = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

    private void saveNeighbors(int[] position, char[][] board, Queue<int[]> queue) {
        int nRows = board.length;
        int nCols = board[0].length;

        for (int[] delta : DIRECTIONS) {
            int nR = position[0] + delta[0];
            int nC = position[1] + delta[1];

            if (nR >= 0 && nR < nRows && nC >= 0 && nC < nCols) {
                if (board[nR][nC] == O_MARKER) {
                    board[nR][nC] = SAFE_MARKER;
                    queue.add(new int[] { nR, nC });
                }
            }
        }
    }

    public void solve(char[][] board) {
        Queue<int[]> queue = new ArrayDeque<>();
        int nRows = board.length;
        int nCols = board[0].length;

        for (int r = 0; r < nRows; r++) {
            for (int c : new int[] { 0, nCols - 1 }) {
                if (board[r][c] == O_MARKER) {
                    queue.add(new int[] { r, c });
                }
            }
        }

        for (int r : new int[] { 0, nRows - 1 }) {
            for (int c = 0; c < nCols; c++) {
                if (board[r][c] == O_MARKER) {
                    queue.add(new int[] { r, c });
                }
            }
        }

        while (!queue.isEmpty()) {
            for (int t = 0; t < queue.size(); t++) {
                int[] pos = queue.remove();
                board[pos[0]][pos[1]] = SAFE_MARKER;
                saveNeighbors(pos, board, queue);
            }
        }

        for (int r = 0; r < nRows; r++) {
            for (int c = 0; c < nCols; c++) {
                if (board[r][c] == O_MARKER) {
                    board[r][c] = X_MARKER;
                }

                if (board[r][c] == SAFE_MARKER) {
                    board[r][c] = O_MARKER;
                }
            }
        }
    }
}