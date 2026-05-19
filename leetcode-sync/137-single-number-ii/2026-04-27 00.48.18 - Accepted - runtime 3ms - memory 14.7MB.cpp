class Solution {
    unordered_set<int> mp;

public:
    int singleNumber(vector<int>& nums) {
        mp.reserve(nums.size() / 2);
        int singleNumber = 0;

        for (auto i : nums) {
            if (mp.find(i) != mp.end()) {
                mp.erase(i);
            } else {
                mp.insert(i);
                singleNumber ^= i;
            }
        }

        return singleNumber;
    }
};