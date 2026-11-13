from collections import deque


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        R, C = len(grid), len(grid[0])
        q = deque()
        fruits = 0
        rotten = 0
        times = 0

        def in_grid(i, j):
            return 0 <= i < R and 0 <= j < C

        for i in range(R):
            for j in range(C):
                if grid[i][j] == 1:
                    fruits += 1
                elif grid[i][j] == 2:
                    rotten += 1
                    q.append((i, j))

        gen_len = rotten
        total_infected = 0

        while q:
            total_infected += gen_len
            while gen_len:
                i, j = q.popleft()
                gen_len -= 1

                for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                    ni = i + dx
                    nj = j + dy
                    if in_grid(ni, nj) and grid[ni][nj] == 1:
                        grid[ni][nj] = 2
                        q.append((ni, nj))
            gen_len = len(q)
            times += 1


        if fruits > 0 and rotten == 0:
            return -1
        if total_infected == 0:
            return 0
        elif rotten + fruits == total_infected:
            return times - 1
        else:
            return -1
