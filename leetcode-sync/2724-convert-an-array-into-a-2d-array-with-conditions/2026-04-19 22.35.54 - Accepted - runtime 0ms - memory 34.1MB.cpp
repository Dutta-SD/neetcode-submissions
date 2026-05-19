class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> count(nums.size() + 1, 0);
        vector<vector<int>> result;

        for (int num : nums) {
            int row = count[num]++;
            if (row == (int)result.size())
                result.emplace_back();
            result[row].push_back(num);
        }

        return result;
    }
};