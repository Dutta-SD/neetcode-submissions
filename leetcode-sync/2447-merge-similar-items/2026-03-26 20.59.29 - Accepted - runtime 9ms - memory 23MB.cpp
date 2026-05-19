#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1,
                                          vector<vector<int>>& items2) {
        map<int, int> allValues;

        for (auto p : items1) {
            allValues[p[0]] = p[1];
        }

        for (auto p : items2) {
            if (allValues.find(p[0]) != allValues.end())
                allValues[p[0]] += p[1];
            else
                allValues[p[0]] = p[1];
        }

        std::vector<std::vector<int>> vecOfVecs;

        for (const auto& pair : allValues) {
            std::vector<int> innerVec;
            innerVec.push_back(pair.first);
            innerVec.push_back(pair.second);
            vecOfVecs.push_back(innerVec);
        }

        return vecOfVecs;
    }
};