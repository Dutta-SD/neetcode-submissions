class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int res = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            set<int> s;
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                s.insert(nums[j]);
                res += (s.find(sum) != s.end());
            }
        }

        return res;
    }
};