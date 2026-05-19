#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;

        int nRows = grid.size();
        int nCols = grid[0].size();
        int islandCount = 0;

        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < nCols; j++) {
                if (grid[i][j] == '1') {
                    islandCount++;
                    sinkIsland(grid, i, j);
                }
            }
        }
        return islandCount;
    }

private:
    void sinkIsland(vector<vector<char>>& grid, int r, int c) {
        int nRows = grid.size();
        int nCols = grid[0].size();

        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '0'; // Mark as visited in-place

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [currR, currC] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = currR + dr[i];
                int nc = currC + dc[i];

                // Check boundaries and if it's land
                if (nr >= 0 && nr < nRows && nc >= 0 && nc < nCols &&
                    grid[nr][nc] == '1') {
                    grid[nr][nc] = '0'; // "Sink" the land immediately
                    q.push({nr, nc});
                }
            }
        }
    }
};
