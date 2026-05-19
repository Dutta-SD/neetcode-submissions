class Solution {
    const vector<int> DX = {1, -1, 0, 0};
    const vector<int> DY = {0, 0, 1, -1};

public:
    int shortestBridge(vector<vector<int>>& grid) {
        const int n = grid.size();
        int gc = 0;
        int marker = -1;
        vector<set<pair<int, int>>> groups(2);

        auto inGrid = [n](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < n;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = marker;
                    queue<pair<int, int>> q;

                    q.push({i, j});

                    while (!q.empty()) {
                        const auto [x, y] = q.front();
                        q.pop();
                        for (auto [dx, dy] : views::zip(DX, DY)) {
                            int x_n = x + dx;
                            int y_n = y + dy;

                            if (inGrid(x_n, y_n)) {
                                if (grid[x_n][y_n] == 0) {
                                    // If water, parent is coastline
                                    groups[gc].insert({x, y});
                                } else if (grid[x_n][y_n] == 1) {
                                    grid[x_n][y_n] = marker;
                                    q.push({x_n, y_n});
                                }
                            }
                        }
                    }

                    // One Island completely marked
                    marker--;
                    gc++;
                }
            }
        }

        int minDist = INT_MAX;

        for (auto z1 : groups[0]) {
            for (auto z2 : groups[1]) {
                minDist = min(minDist, abs(z1.first - z2.first) +
                                           abs(z1.second - z2.second));
            }
        }

        return --minDist;
    }
};