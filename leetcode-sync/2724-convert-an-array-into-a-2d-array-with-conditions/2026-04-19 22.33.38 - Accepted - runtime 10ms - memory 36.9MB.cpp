class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> rowIndexes(nums.size(), 0);
        vector<int> lastSeenIndexes(500, 0);
        int numRows = -1;

        for (int i = 0; i < nums.size(); i++) {
            rowIndexes[i] = lastSeenIndexes[nums[i]]++;
            numRows = max(numRows, rowIndexes[i]);
        }

        vector<vector<int>> result(numRows + 1);

        for (int i = 0; i < nums.size(); i++) {
            result[rowIndexes[i]].push_back(nums[i]);
        }

        return result;
    }
};