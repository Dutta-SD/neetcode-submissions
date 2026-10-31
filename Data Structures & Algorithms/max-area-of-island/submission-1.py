class Solution:
    def sink(self, grid: List[List[str]], r: int, c: int, curr_island_area: list[int]) -> None:
        R = len(grid)
        C = len(grid[0])
        if r < 0 or r >= R or c < 0 or c >= C or grid[r][c] == 0:
            return

        grid[r][c] = 0
        curr_island_area[0] += 1

        self.sink(grid, r, c + 1, curr_island_area)
        self.sink(grid, r, c - 1, curr_island_area)
        self.sink(grid, r + 1, c, curr_island_area)
        self.sink(grid, r - 1, c, curr_island_area)

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if grid is None:
            return 0

        R = len(grid)
        C = len(grid[0])
        curr_island_area = [0]
        max_island_area = 0

        for r in range(R):
            for c in range(C):
                if grid[r][c] == 1:
                    curr_island_area[0] = 0
                    self.sink(grid, r, c, curr_island_area)
                    max_island_area = max(curr_island_area[0], max_island_area)

        return max_island_area
