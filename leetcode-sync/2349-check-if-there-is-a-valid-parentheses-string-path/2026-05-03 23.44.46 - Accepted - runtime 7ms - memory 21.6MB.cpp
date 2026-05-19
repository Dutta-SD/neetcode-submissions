class Solution {
    int nR, nC;
    // memo[row][col][balance]
    int memo[101][101][101]; 

    bool dfs(int i, int j, int bal, const vector<vector<char>>& grid) {
        // 1. Base Cases & Pruning
        if (bal < 0 || bal > (nR + nC) / 2) return false;
        if (i == nR - 1 && j == nC - 1) return (bal == 0);
        if (memo[i][j][bal] != -1) return memo[i][j][bal];

        bool found = false;
        
        // Move Right
        if (j + 1 < nC) {
            int nextBal = bal + (grid[i][j + 1] == '(' ? 1 : -1);
            if (dfs(i, j + 1, nextBal, grid)) found = true;
        }
        
        // Move Down
        if (!found && i + 1 < nR) {
            int nextBal = bal + (grid[i + 1][j] == '(' ? 1 : -1);
            if (dfs(i + 1, j, nextBal, grid)) found = true;
        }

        return memo[i][j][bal] = found;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        nR = grid.size();
        nC = grid[0].size();
        
        // Quick check: total length must be even and start/end must be valid
        if ((nR + nC - 1) % 2 != 0 || grid[0][0] == ')' || grid[nR-1][nC-1] == '(') 
            return false;

        memset(memo, -1, sizeof(memo));
        return dfs(0, 0, 1, grid); // Start with balance 1 because grid[0][0] is '('
    }
};
