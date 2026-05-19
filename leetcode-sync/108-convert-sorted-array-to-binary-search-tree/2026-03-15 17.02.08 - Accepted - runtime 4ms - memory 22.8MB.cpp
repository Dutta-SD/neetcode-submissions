class Solution {
public:
    TreeNode* makeBST(vector<int>& nums, int start, int end) {
        // Base case: if range is invalid, return null
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        
        // Use 'new' to create a pointer to a node
        TreeNode* node = new TreeNode(nums[mid]);
        
        // Recursively build left and right subtrees
        node->left = makeBST(nums, start, mid - 1);
        node->right = makeBST(nums, mid + 1, end);
        
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeBST(nums, 0, nums.size() - 1);
    }
};
