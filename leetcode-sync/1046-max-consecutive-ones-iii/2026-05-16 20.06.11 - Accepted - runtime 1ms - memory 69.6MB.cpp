class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroCounter = 0;
        int l = 0, r = 0, w = -1;
        int n = nums.size();

        while (r < n) {
            if (nums[r] == 0) {
                zeroCounter++;
                if (zeroCounter == k + 1) {
                    while (l < n && nums[l] == 1) {
                        l++;
                    }
                    l++;
                    zeroCounter--;
                }
            }
            r++;
            w = max(w, r - l);
        }

        return w;
    }
};