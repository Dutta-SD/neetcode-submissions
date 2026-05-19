class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size() - 1;
        
        while (i <= j) {
            if (nums[i] == val) {
                // Swap the target value with the current end of the "active" array
                // This preserves both values, just reorders them
                std::swap(nums[i], nums[j]);
                // Shrink the search range from the back
                j--;
                // DO NOT increment i. We must re-check the new element swapped to nums[i]
            } else {
                // If it's not the target, move the front pointer forward
                i++;
            }
        }
        // Return i, which is the count of elements not equal to val
        return i; 
    }
};
