class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int nR = matrix.size();
        int nC = matrix[0].size();

        for(int i = 0; i < nR; i++){
            for (int j = 0; j < nC; j++){
                if(!i || !j) {
                    int match = matrix[i][j];
                    for(int k = 1; i+k < nR && j+k < nC; k++){
                        if(match != matrix[i+k][j+k]) return false;
                    }
                }
            }
        }
        return true;
    }
};