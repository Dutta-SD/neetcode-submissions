class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int x : nums)
            freq[x]++;

        // Bucket sort: index = frequency, value = elements with that frequency
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        for (auto& [num, cnt] : freq)
            buckets[cnt].push_back(num);

        vector<int> result;
        for (int i = n; i >= 0 && (int)result.size() < k; i--)
            for (int x : buckets[i])
                result.push_back(x);
        return result;
    }
    // Time: O(n), Space: O(n) — beats heap approach O(n log k)
};