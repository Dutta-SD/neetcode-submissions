class Solution {
    private static final char LAND = '1';
    private static final char WATER = '0';

    private void sink(char[][] grid, int r, int c) {
        final int nRows = grid.length;
        final int nCols = grid[0].length;

        if (r >= 0 && r < nRows && c >= 0 && c < nCols) {
            if (grid[r][c] == WATER)
                return;
            grid[r][c] = WATER;
            sink(grid, r, c + 1);
            sink(grid, r, c - 1);
            sink(grid, r + 1, c);
            sink(grid, r - 1, c);
        }
    }

    public int numIslands(char[][] grid) {
        final int nRows = grid.length;
        final int nCols = grid[0].length;
        int numIslands = 0;

        for (int r = 0; r < nRows; r++) {
            for (int c = 0; c < nCols; c++) {
                if (grid[r][c] == LAND) {
                    numIslands++;
                    sink(grid, r, c);
                }
            }
        }

        return numIslands;
    }
}