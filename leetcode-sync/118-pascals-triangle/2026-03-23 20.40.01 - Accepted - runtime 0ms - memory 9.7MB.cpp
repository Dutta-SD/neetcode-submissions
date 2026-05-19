class Solution {
public:
    vector<vector<int>> generate(int n) {
        if (n == 1) return {{1}};
        if (n == 2) return {{1}, {1, 1}};

        vector<vector<int>> pascalsTriangle = {{1}, {1, 1}};

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