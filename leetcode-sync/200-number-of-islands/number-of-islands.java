class Solution {
    private static final int[][] DIRS = {{1,0},{-1,0},{0,1},{0,-1}};

    public int numIslands(char[][] grid) {
        int rows = grid.length, cols = grid[0].length, count = 0;
        Queue<int[]> queue = new ArrayDeque<>();   // ArrayDeque > LinkedList

        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                if (grid[r][c] == '1') {
                    count++;
                    grid[r][c] = '0';               // mark seed AT enqueue
                    queue.add(new int[]{r, c});
                    while (!queue.isEmpty()) {
                        int[] cell = queue.remove();
                        for (int[] d : DIRS) {
                            int x = cell[0] + d[0], y = cell[1] + d[1];
                            if (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == '1') {
                                grid[x][y] = '0';   // mark neighbor AT enqueue
                                queue.add(new int[]{x, y});
                            }
                        }
                    }
                }
        return count;
    }
}