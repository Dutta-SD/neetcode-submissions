class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        auto is_even = [](int i){ return i % 2 == 0; };

        std::partition(nums.begin(), nums.end(), is_even);

        return nums;

        
    }
};