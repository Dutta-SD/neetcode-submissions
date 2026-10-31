class Solution:
    def sink(self, grid, r, c, area):
        R, C = len(grid), len(grid[0])
        if r < 0 or r >= R or c < 0 or c >= C or grid[r][c] == 0:
            return
        grid[r][c] = 0               # mark visited
        area[0] += 1                 # mutate the shared list
        self.sink(grid, r+1, c, area)
        self.sink(grid, r-1, c, area)
        self.sink(grid, r, c+1, area)
        self.sink(grid, r, c-1, area)

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if not grid: return 0
        max_island = 0
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] == 1:
                    area = [0]                     # mutable holder
                    self.sink(grid, r, c, area)
                    max_island = max(max_island, area[0])
        return max_island