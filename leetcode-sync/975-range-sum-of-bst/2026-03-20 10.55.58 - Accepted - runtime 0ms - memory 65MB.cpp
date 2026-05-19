/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool inRange(int x, int low, int high) {
        return x >= low && x <= high;
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        long sum = inRange(root -> val, low, high) ? root -> val : 0;
        return sum + rangeSumBST(root -> left, low, high) + rangeSumBST(root -> right, low, high);
    }
};