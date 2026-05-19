class Solution {

    private static class Pair{
        int row;
        int col;
        Pair(int row, int col) {
            this.row = row;
            this.col = col;
        }
    }

    private boolean isLand(char value) {
        return (value == '1');
    }

    private boolean isValidDim(int dim, int maxDim) {
        return (dim >= 0 && dim < maxDim);
    }

    private void applyBfsOnComponent(int row, int col, char[][] grid, boolean[][] visited) {
            // Guaranteed (row, col is land)
            int nRows = grid.length;
            int nCols = grid[0].length;
            Queue<Pair> q = new LinkedList<Pair>();

            q.add(new Pair(row, col));

            while (!q.isEmpty()) {
                // Add Land neighbors
                Pair currPosition = q.poll();
                for (int dRow = -1; dRow <= 1; dRow++) {
                    for (int dCol = -1; dCol <= 1; dCol++) {
                        if (Math.abs(dRow - dCol) == 1) {
                            int newRow = currPosition.row + dRow;
                            int newCol = currPosition.col + dCol;

                            if (
                                isValidDim(newRow, nRows) && 
                                isValidDim(newCol, nCols) && 
                                isLand(grid[newRow][newCol]) &&
                                !visited[newRow][newCol]
                            ) {
                                q.add(new Pair(newRow, newCol));
                                visited[newRow][newCol] = true;
                            }
                        }
                    }
                }
                 
            }
    }

    public int numIslands(char[][] grid) {
        // Setup
        int nRows = grid.length;
        int nCols = grid[0].length;
        boolean[][] visited = new boolean[nRows][nCols];

        int countIslands = 0;

        for (int row = 0; row < nRows; row++) {
            for (int col = 0; col < nCols; col++) {
                if (isLand(grid[row][col]) && !visited[row][col]) {
                    applyBfsOnComponent(row, col, grid, visited);
                    countIslands++;
                }
            }
        }
        return countIslands;
    }
}