class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<float> s;
        for (int i = 0; i < nums.size() / 2; i++) {
            int x = nums[i];
            int y = nums[nums.size() - 1 - i];
            s.insert((float)(x+y) / 2.0);
        }
        return s.size();       
    }
};