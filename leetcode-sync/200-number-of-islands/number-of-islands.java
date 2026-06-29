class Solution {
    private static final char WATER = '0';
    private static final char LAND = '1';

    private record Pair<K, V>(K first, V second) {
    }

    private static final List<Pair> DIRECTIONS = List.of(
            new Pair<>(0, 1),
            new Pair<>(0, -1),
            new Pair<>(1, 0),
            new Pair<>(-1, 0));

    private boolean isInsideGrid(int r, int c, char[][] grid) {
        int nRows = grid.length;
        int nCols = grid[0].length;
        return (r >= 0 && r < nRows && c >= 0 && c < nCols);
    }

    public int numIslands(char[][] grid) {
        int nRows = grid.length;
        int nCols = grid[0].length;
        int numIslands = 0;

        Queue<Pair<Integer, Integer>> queue = new LinkedList<>();

        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < nCols; j++) {
                if (grid[i][j] == LAND) {
                    numIslands++;
                    queue.add(new Pair(i, j));

                    while (!queue.isEmpty()) {
                        Pair<Integer, Integer> p = queue.remove();
                        grid[p.first][p.second] = WATER;
                        for (Pair<Integer, Integer> d : DIRECTIONS) {
                            int x = p.first + d.first;
                            int y = p.second + d.second;
                            if (isInsideGrid(x, y, grid) && grid[x][y] == LAND) {
                                grid[x][y] = WATER;
                                queue.add(new Pair(x, y));
                            }
                        }
                    }
                }
            }
        }

        return numIslands;
    }
}