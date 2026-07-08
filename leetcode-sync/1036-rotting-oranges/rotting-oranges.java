class Solution {
    private static final int ROTTEN_ORANGE = 2;
    private static final int FRESH_ORANGE = 1;
    private static final int NOT_POSSIBLE_STATE = -1;
    private static final int EMPTY_CELL = 0;

    private static final int[][] DIRECTIONS = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

    private int numOranges = 0;
    private int numRottenOranges = 0;

    private record Pair<S>(S first, S second) {
    }

    private void updateNeighbors(final Pair<Integer> rottenOrangePosition, final int[][] grid,
            final Queue<Pair<Integer>> queue) {
        int nRows = grid.length;
        int nCols = grid[0].length;

        for (int[] delta : DIRECTIONS) {
            int nextRow = rottenOrangePosition.first + delta[0];
            int nextCol = rottenOrangePosition.second + delta[1];
            if (nextRow >= 0 && nextRow < nRows && nextCol >= 0 && nextCol < nCols) {
                if (grid[nextRow][nextCol] == FRESH_ORANGE) {
                    numRottenOranges++;

                    grid[nextRow][nextCol] = ROTTEN_ORANGE;
                    queue.add(new Pair(nextRow, nextCol));
                }
            }
        }
    }

    public int orangesRotting(int[][] grid) {
        int tick = 0;
        Queue<Pair<Integer>> queue = new ArrayDeque<>();
        Queue<Pair<Integer>> currQueue = new ArrayDeque<>();

        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[0].length; c++) {
                if (grid[r][c] != EMPTY_CELL) {
                    numOranges++;
                }

                if (grid[r][c] == ROTTEN_ORANGE) {
                    numRottenOranges++;
                    queue.add(new Pair(r, c));
                }
            }
        }

        if (numOranges == numRottenOranges)
            return 0;

        while (true) {
            while (!queue.isEmpty()) {
                currQueue.add(queue.remove());
            }
            while (!currQueue.isEmpty()) {
                Pair<Integer> rottenOrangePosition = currQueue.remove();
                updateNeighbors(rottenOrangePosition, grid, queue);
            }
            if (queue.isEmpty())
                break;
            tick++;
        }

        return numOranges == numRottenOranges ? tick : NOT_POSSIBLE_STATE;
    }
}