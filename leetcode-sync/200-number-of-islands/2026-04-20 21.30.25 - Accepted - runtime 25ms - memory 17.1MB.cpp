class UnionFind {
    vector<int> parent;
    int count;
public:
    UnionFind(vector<vector<char>>& grid) {
        int R = grid.size(), C = grid[0].size();
        count = 0;
        parent.resize(R * C, -1);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == '1') {
                    parent[i * C + j] = i * C + j;
                    count++;
                }
            }
        }
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) {
            parent[rootI] = rootJ;
            count--; // Merged two sets into one
        }
    }

    int getCount() { return count; }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int R = grid.size(), C = grid[0].size();
        UnionFind uf(grid);

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == '1') {
                    // Only need to check Right and Down to avoid redundant unions
                    if (c + 1 < C && grid[r][c+1] == '1') uf.unite(r * C + c, r * C + (c + 1));
                    if (r + 1 < R && grid[r+1][c] == '1') uf.unite(r * C + c, (r + 1) * C + c);
                }
            }
        }
        return uf.getCount();
    }
};
