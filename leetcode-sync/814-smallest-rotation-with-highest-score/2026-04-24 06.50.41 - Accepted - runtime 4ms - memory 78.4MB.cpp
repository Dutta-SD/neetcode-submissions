class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        int score = 0;
        vector<int> diffs(n, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] <= i)
                score++;

            diffs[(i + 1) % n]++;
            diffs[(i - nums[i] + 1 + n) % n]--;
        }

        int bestK = 0, bestScore = score;

        for (int k = 1; k < n; k++) {
            score += diffs[k];
            if (score > bestScore) {
                bestScore = score;
                bestK = k;
            }
        }

        return bestK;
    }
};