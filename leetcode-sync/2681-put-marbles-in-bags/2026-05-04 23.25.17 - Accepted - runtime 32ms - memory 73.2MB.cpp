class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if (k == 1 || k == weights.size())
            return 0;

        vector<long long> pairSums;
        int n = weights.size();

        for (int i = 0; i < n - 1; i++) {
            pairSums.push_back((long long)weights[i] + weights[i + 1]);
        }

        sort(pairSums.begin(), pairSums.end());

        long long minScore = 0;
        long long maxScore = 0;

        for (int i = 0; i < k - 1; i++) {
            minScore += pairSums[i];
            maxScore += pairSums[pairSums.size() - 1 - i];
        }

        return maxScore - minScore;
    }
};