class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0;

        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        double avg = (double)sum / k;

        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            avg = max(avg, (double)sum / k);
        }

        return avg;
    }
};