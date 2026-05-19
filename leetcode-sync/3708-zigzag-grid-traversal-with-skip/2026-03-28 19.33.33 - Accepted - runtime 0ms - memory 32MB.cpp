class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int nRows = grid.size();
        int nCols = grid[0].size();

        bool selectCell = true;
        bool flipDirection = false;

        vector<int> traversal;

        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < nCols; j++) {
                int cIdx = flipDirection ? nCols - j - 1 : j;
                if (selectCell) {
                    traversal.push_back(grid[i][cIdx]);
                }
                selectCell = !selectCell;
            }
            flipDirection = !flipDirection;
        }

        return traversal;
    }
};