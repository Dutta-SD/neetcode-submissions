class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        long bobSum = 0;
        long aliceSum = 0;

        for (auto c : aliceSizes)
            aliceSum += c;
        for (auto c : bobSizes)
            bobSum += c;

        for (auto a : aliceSizes) {
            for (auto b : bobSizes) {
                if (aliceSum - a + b == bobSum - b + a)
                    return {a, b};
            }
        }

        return {};
    }
};