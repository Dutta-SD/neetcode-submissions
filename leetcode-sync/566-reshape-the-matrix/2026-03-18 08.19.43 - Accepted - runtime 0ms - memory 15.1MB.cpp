class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        int e, num;
        if (m*n != r*c) return mat;
        std::vector<std::vector<int>> mat_reshaped(r, std::vector<int>(c, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                e = mat[i][j];
                num = i*n+j;
                mat_reshaped[num/c][num%c] = e;
            }
        }
        return mat_reshaped;
    }
};