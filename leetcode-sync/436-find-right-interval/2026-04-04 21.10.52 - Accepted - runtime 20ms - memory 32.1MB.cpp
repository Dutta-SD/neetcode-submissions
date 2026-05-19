class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> intervalsWithIndexes(intervals.size());
        vector<int> values(intervals.size());
        int currEnd;

        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            intervalsWithIndexes[i] = {start, end, i};
        }

        std::sort(intervalsWithIndexes.begin(), intervalsWithIndexes.end());

        for (int i = 0; i < intervals.size(); i++) {
            currEnd = intervals[i][1];
            auto e = std::lower_bound(intervalsWithIndexes.begin(),
                                      intervalsWithIndexes.end(), currEnd,
                                      [](const std::vector<int>& vec, int val) {
                                          return vec[0] < val;
                                      });
            values[i] = e == intervalsWithIndexes.end() ? -1 : (*e)[2];
        }

        return values;
    }
};