class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Basic Pruning
        // 1. Total steps (m + n - 1) must be even for a valid parenthesis string
        // 2. Must start with '(' and end with ')'
        if ((m + n - 1) % 2 != 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }

        // dp[i][j] is a bitset where the k-th bit is 1 if balance 'k' is reachable at (i, j)
        vector<vector<bitset<101>>> dp(m, vector<bitset<101>>(n));

        // Initial state at (0, 0)
        dp[0][0][1] = 1; 

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;

                bitset<101> reachable_balances;
                // Inherit possible balances from the cell above
                if (i > 0) reachable_balances |= dp[i - 1][j];
                // Inherit possible balances from the cell to the left
                if (j > 0) reachable_balances |= dp[i][j - 1];

                if (grid[i][j] == '(') {
                    // '(' increases balance: shift all bits left by 1
                    dp[i][j] = reachable_balances << 1;
                } else {
                    // ')' decreases balance: shift all bits right by 1
                    dp[i][j] = reachable_balances >> 1;
                }
            }
        }

        // The path is valid if balance 0 is possible at the last cell
        return dp[m - 1][n - 1][0];
    }
};
