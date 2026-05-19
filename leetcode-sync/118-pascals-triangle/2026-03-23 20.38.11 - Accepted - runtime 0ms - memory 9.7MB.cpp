class Solution {
private:
    const int ONE = 1;
    const vector<int> ROW_1 = {1};
    const vector<int> ROW_2 = {1, 1};
public:
    vector<vector<int>> generate(int n) {
        if (n == 1) return {ROW_1};
        if (n == 2) return {ROW_1, ROW_2};

        vector<vector<int>> pascalsTriangle = {ROW_1, ROW_2};

        for (int i = 3; i <= n; i++) {
            vector<int> currRow = {1};
            vector<int> previousRow = pascalsTriangle.back();
            for (int j = 0; j < previousRow.size() - 1; j++) {
                currRow.push_back(previousRow[j] + previousRow[j+1]);
            }
            currRow.push_back(1);
            pascalsTriangle.push_back(currRow);
        }

        return pascalsTriangle;
    }
};