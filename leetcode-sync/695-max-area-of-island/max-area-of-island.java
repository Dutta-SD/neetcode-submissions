class Solution {
    private static final int LAND = 1;
    private static final int WATER = 0;

    private int nRows;
    private int nCols;

    private boolean inGrid(int x, int y, int[][] grid) {
        return (x >= 0 &&
                x < nRows &&
                y >= 0 &&
                y < nCols);
    }

    private int sink(int x, int y, int[][] grid) {
        if (!inGrid(x, y, grid) || grid[x][y] == WATER)
            return 0;
        grid[x][y] = WATER;
        return (1 +
                sink(x + 1, y, grid) +
                sink(x - 1, y, grid) +
                sink(x, y + 1, grid) +
                sink(x, y - 1, grid));

    }

    public int maxAreaOfIsland(int[][] grid) {
        nRows = grid.length;
        nCols = grid[0].length;
        int maxArea = 0;

        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < nCols; j++) {
                if (grid[i][j] == LAND) {
                    maxArea = Math.max(maxArea, sink(i, j, grid));
                }
            }
        }

        return maxArea;
    }
}