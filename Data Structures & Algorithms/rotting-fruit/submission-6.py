from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        R, C = len(grid), len(grid[0])
        q = deque()
        fresh = 0

        for i in range(R):
            for j in range(C):
                if grid[i][j] == 1:
                    fresh += 1
                elif grid[i][j] == 2:
                    q.append((i, j))

        if fresh == 0:      # fast exit: nothing to rot
            return 0
        if not q:           # fast exit: fresh oranges but no rotten source
            return -1

        minutes = 0
        while q:
            minutes += 1
            for _ in range(len(q)):
                i, j = q.popleft()
                for ni, nj in ((i-1, j), (i+1, j), (i, j-1), (i, j+1)):
                    if 0 <= ni < R and 0 <= nj < C and grid[ni][nj] == 1:
                        grid[ni][nj] = 2
                        fresh -= 1
                        q.append((ni, nj))
            if fresh == 0:  # fast exit: all rotted
                return minutes

        return -1