class Solution {
    private static final int[][] DIRECTIONS = {
            { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
    };

    private record State(int cost, int row, int col) {
    }

    private boolean isInside(int row, int col, int rows, int cols) {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }

    public int minimumObstacles(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;

        int[][] dist = new int[rows][cols];
        for (int[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        Deque<State> deque = new ArrayDeque<>();
        dist[0][0] = 0;
        deque.addFirst(new State(0, 0, 0));

        while (!deque.isEmpty()) {
            State current = deque.removeFirst();
            int cost = current.cost();
            int row = current.row();
            int col = current.col();

            if (cost != dist[row][col])
                continue;
            if (row == rows - 1 && col == cols - 1)
                return cost;

            for (int[] direction : DIRECTIONS) {
                int nextRow = row + direction[0];
                int nextCol = col + direction[1];

                if (!isInside(nextRow, nextCol, rows, cols))
                    continue;

                int moveCost = grid[nextRow][nextCol];
                int candidate = cost + moveCost;

                if (candidate < dist[nextRow][nextCol]) {
                    dist[nextRow][nextCol] = candidate;
                    State next = new State(candidate, nextRow, nextCol);

                    if (moveCost == 0) {
                        deque.addFirst(next);
                    } else {
                        deque.addLast(next);
                    }
                }
            }
        }

        return -1;
    }
}