from collections import deque

INF = 2147483647
TREASURE = 0
DIRS = [(-1, 0), (1, 0), (0, -1), (0, 1)]


class Solution:
    def in_grid(self, i, j, R, C):
        return 0 <= i < R and 0 <= j < C

    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        R, C = len(grid), len(grid[0])
        q = deque()

        for i in range(R):
            for j in range(C):
                if grid[i][j] == TREASURE:
                    q.append((i, j))

        while q:
            i, j = q.popleft()
            for dx, dy in DIRS:
                ni, nj = i + dx, j + dy
                if self.in_grid(ni, nj, R, C) and grid[ni][nj] == INF:
                    grid[ni][nj] = grid[i][j] + 1
                    q.append((ni, nj))
