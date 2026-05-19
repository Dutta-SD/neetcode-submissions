class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int adder = 1;
        int x;
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            x = *it + adder;
            result.push_back(x % 10);
            adder = x / 10;
        }
        if (adder) result.push_back(adder);
        reverse(result.begin(), result.end());
        return result;
    }
};