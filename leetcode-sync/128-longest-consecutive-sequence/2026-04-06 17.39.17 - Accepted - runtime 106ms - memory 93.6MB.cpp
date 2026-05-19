class Solution {
    unordered_map<int, int> valToIndex; // Maps value to its index in nums
    vector<int> parent;
    vector<int> size; // Tracks the length of the consecutive sequence

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) {
            // Union by size
            parent[rootI] = rootJ;
            size[rootJ] += size[rootI];
        }
    }

public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = nums.size();
        parent.resize(n);
        size.assign(n, 1);
        valToIndex.clear();

        for (int i = 0; i < n; i++) {
            // Ignore duplicates to avoid logic errors
            if (valToIndex.count(nums[i])) continue;
            
            parent[i] = i;
            valToIndex[nums[i]] = i;

            // Check if (nums[i] - 1) or (nums[i] + 1) exists
            if (valToIndex.count(nums[i] - 1)) {
                unite(i, valToIndex[nums[i] - 1]);
            }
            if (valToIndex.count(nums[i] + 1)) {
                unite(i, valToIndex[nums[i] + 1]);
            }
        }

        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            // Only roots hold the final size of the sequence
            if (parent[i] == i) maxLen = max(maxLen, size[i]);
        }
        return maxLen;
    }
};
