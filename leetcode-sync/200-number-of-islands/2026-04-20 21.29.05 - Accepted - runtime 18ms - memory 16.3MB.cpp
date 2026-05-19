class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nRows = grid.size();
        int nCols = grid[0].size();
        int islandCount = 0;

        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < nCols; j++) {
                if (grid[i][j] == '1') {
                    islandCount++;
                    dfs(grid, i, j);
                }
            }
        }
        return islandCount;
    }

private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nRows = grid.size();
        int nCols = grid[0].size();

        // 1. Base Case: Boundary check and skip if water ('0')
        if (r < 0 || r >= nRows || c < 0 || c >= nCols || grid[r][c] == '0') {
            return;
        }

        // 2. Mark as visited immediately (Sink the land)
        grid[r][c] = '0';

        // 3. Recurse in all 4 directions
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }
};
