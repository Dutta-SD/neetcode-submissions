class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;

        int idx1 = 0;
        int idx2 = 0;

        while (idx1 < m && idx2 < n) {
            if (nums1[idx1] < nums2[idx2]) {
                result.push_back(nums1[idx1++]);
            } else {
                result.push_back(nums2[idx2++]);
            }
        }

        if (idx1 == m) {
            while (idx2 < n) {
                result.push_back(nums2[idx2++]);
            }
        }

        if (idx2 == n) {
            while (idx1 < m) {
                result.push_back(nums1[idx1++]);
            }
        }

        nums1 = result;
    }
};