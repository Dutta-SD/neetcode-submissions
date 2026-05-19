class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1; // Base case: a prefix sum of 0 has occurred once
        int current_sum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            current_sum += nums[i];
            
            // If (current_sum - k) exists in the map, it means there is a 
            // prefix sum such that: current_sum - prefix_sum = k
            if (mp.find(current_sum - k) != mp.end()) {
                count += mp[current_sum - k];
            }
            
            // Store/increment the frequency of the current prefix sum
            mp[current_sum]++;
        }
        return count;
    }
};
