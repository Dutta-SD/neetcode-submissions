class Solution {
    private static int[][] DIRECTIONS = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

    private record State(int cost, int row, int col) {
    }

    private static boolean isInside(int r, int c, int R, int C) {
        return r >= 0 && r < R && c >= 0 && c < C;
    }

    public int minimumObstacles(int[][] grid) {
        int R = grid.length;
        int C = grid[0].length;
        int[][] dist = new int[R][C];

        for (int[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        dist[0][0] = 0;

        PriorityQueue<State> pq = new PriorityQueue<>(Comparator.comparingInt(State::cost));

        pq.add(new State(0, 0, 0));

        while (!pq.isEmpty()) {
            State currCell = pq.remove();
            int r = currCell.row();
            int c = currCell.col();
            int cCost = currCell.cost();

            if (dist[r][c] != cCost) continue;

            for (int[] d : DIRECTIONS) {
                int newR = r + d[0];
                int newC = c + d[1];
                if (!isInside(newR, newC, R, C)) continue;

                int candidate = cCost + grid[newR][newC];

                if (candidate < dist[newR][newC]){
                    dist[newR][newC] = candidate;
                    pq.add(new State(candidate, newR, newC));
                }
            } 
        }
        return dist[R-1][C-1];
    }
}