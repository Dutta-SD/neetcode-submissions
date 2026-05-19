class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto n : nums) {
            res ^= n;
        }

        unsigned l = (unsigned)res & -(unsigned)res;
        int a = 0;

        for (auto n : nums) {
            if (l & n) {
                a ^= n;
            }
        }

        return {a, res ^ a};
    }
};