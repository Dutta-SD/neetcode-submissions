class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        // Size + 1 to prevent out-of-bounds for the largest possible group
        vector<vector<vector<int>>> groups(groupSizes.size() + 1);
        vector<vector<int>> result;

        for (int i = 0; i < groupSizes.size(); ++i) {
            int sz = groupSizes[i];
            // If no group exists for this size, or the last one is full, add a
            // new sub-vector
            if (groups[sz].empty() || groups[sz].back().size() == sz) {
                groups[sz].push_back({});
            }
            groups[sz].back().push_back(i);
        }

        // Flattening the groups into the result
        for (auto& v : groups) {
            for (auto& g : v) {
                result.push_back(std::move(g));
            }
        }
        return result;
    }
};