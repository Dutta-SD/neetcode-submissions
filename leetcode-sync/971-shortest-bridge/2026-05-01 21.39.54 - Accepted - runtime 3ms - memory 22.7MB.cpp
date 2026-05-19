#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
    // Directions for traversing the grid (N, S, E, W)
    static constexpr int DR[] = {0, 0, 1, -1};
    static constexpr int DC[] = {1, -1, 0, 0};

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = static_cast<int>(grid.size());
        queue<pair<int, int>> q;

        // 1. Identify the first island and seed the BFS queue
        bool found = false;
        for (int i = 0; i < n && !found; ++i) {
            for (int j = 0; j < n && !found; ++j) {
                if (grid[i][j] == 1) {
                    markIsland(grid, q, i, j, n);
                    found = true;
                }
            }
        }

        // 2. Multi-source BFS to find the shortest path to the second island
        int distance = 0;
        while (!q.empty()) {
            int layerSize = q.size();
            
            while (layerSize--) {
                auto [r, c] = q.front();
                q.pop();

                for (int i = 0; i < 4; ++i) {
                    int nr = r + DR[i];
                    int nc = c + DC[i];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                        if (grid[nr][nc] == 1) {
                            return distance; // Reached the second island
                        }
                        if (grid[nr][nc] == 0) {
                            grid[nr][nc] = 2; // Mark as visited water
                            q.push({nr, nc});
                        }
                    }
                }
            }
            distance++;
        }

        return distance;
    }

private:
    // Uses BFS to mark the entire first island and add its cells to the source queue
    void markIsland(vector<vector<int>>& grid, queue<pair<int, int>>& q, int r, int c, int n) {
        queue<pair<int, int>> islandQ;
        
        auto pushToQueues = [&](int row, int col) {
            grid[row][col] = 2; // Mark as part of the source island
            islandQ.push({row, col});
            q.push({row, col});
        };

        pushToQueues(r, c);

        while (!islandQ.empty()) {
            auto [currR, currC] = islandQ.front();
            islandQ.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = currR + DR[i];
                int nc = currC + DC[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    pushToQueues(nr, nc);
                }
            }
        }
    }
};
