class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        set<pair<int, int>, std::greater<pair<int, int>>> s;
        unordered_map<int, int> c;

        for (auto n : nums) {
            c[n]++;
        }

        for (auto x : c) {
            s.insert({x.second, x.first});
        }

        vector<int> res;

        for (auto x : s){
            if (!k) break;
            k--;
            res.push_back(x.second);
        }

        return res;
    }
};