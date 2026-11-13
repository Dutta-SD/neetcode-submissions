import queue

INF = 2147483647
WATER = -1
TREASURE = 0


class Solution:
    def in_grid(self, i, j, R, C):
        return i >= 0 and i < R and j >= 0 and j < C

    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        R, C = len(grid), len(grid[0])
        q = queue.SimpleQueue()

        for i in range(R):
            for j in range(C):
                if grid[i][j] == TREASURE:
                    q.put((i, j))

        while not q.empty():
            i, j = q.get(block=False)
            for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                ni, nj = i + dx, j + dy
                if self.in_grid(ni, nj, R, C) and grid[ni][nj] == INF:
                    grid[ni][nj] = min(grid[ni][nj], grid[i][j] + 1)
                    q.put((ni, nj))
