#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> intervalsWithIndexes;
        vector<int> values;

        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            intervalsWithIndexes.push_back({start, end, i});
        }

        std::sort(intervalsWithIndexes.begin(), intervalsWithIndexes.end());

        for (int i = 0; i < intervals.size(); i++) {
            int foundIdx;
            int currEnd = intervals[i][1];
            auto e = std::lower_bound(intervalsWithIndexes.begin(),
                                      intervalsWithIndexes.end(), currEnd,
                                      [](const std::vector<int>& vec, int val) {
                                          return vec[0] < val;
                                      });
            if (e == intervalsWithIndexes.end()) {
                foundIdx = -1;
            } else {
                foundIdx = (*e)[2];
            }
            values.push_back(foundIdx);
        }

        return values;
    }
};