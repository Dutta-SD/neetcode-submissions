#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) return n >= 2; // Special case: any two adjacent elements are "increasing" subarrays of length 1

        // The total window (two subarrays of length k) spans 2*k elements.
        // So the starting index 'i' can only go up to n - 2*k.
        for (int i = 0; i <= n - 2 * k; i++) {
            int j1 = 0;
            // Check first subarray: from i to i + k - 1
            // Needs k-1 successful comparisons to have k increasing elements
            while (j1 < k - 1 && nums[i + j1] < nums[i + j1 + 1]) {
                j1++;
            }

            if (j1 == k - 1) {
                int j2 = 0;
                int start2 = i + k; // Second subarray must start exactly after the first
                
                // Check second subarray: from start2 to start2 + k - 1
                while (j2 < k - 1 && nums[start2 + j2] < nums[start2 + j2 + 1]) {
                    j2++;
                }
                
                if (j2 == k - 1) return true;
            }
        }
        return false;
    }
};
