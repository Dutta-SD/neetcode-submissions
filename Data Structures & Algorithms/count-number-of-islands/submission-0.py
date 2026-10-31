class Solution:
    def sink(self, grid: List[List[str]], r: int, c: int) -> None:
        R = len(grid)
        C = len(grid[0])
        if r < 0 or r >= R or c < 0 or c >= C or grid[r][c] == "0":
            return

        grid[r][c] = "0"

        self.sink(grid, r, c + 1)
        self.sink(grid, r, c - 1)
        self.sink(grid, r + 1, c)
        self.sink(grid, r - 1, c)

    def numIslands(self, grid: List[List[str]]) -> int:
        if grid is None:
            return 0

        R = len(grid)
        C = len(grid[0])
        num_islands = 0

        for r in range(R):
            for c in range(C):
                if grid[r][c] == "1":
                    num_islands += 1
                    self.sink(grid, r, c)

        return num_islands
