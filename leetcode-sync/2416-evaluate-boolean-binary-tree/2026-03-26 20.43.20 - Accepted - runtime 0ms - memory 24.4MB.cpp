/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    const int OR_OP = 2;

public:
    bool evaluateTree(TreeNode* root) {
        if (!root->left && !root->right)
            return root->val;

        // As full binary tree, guaranteed both children or leaf
        bool leftVal = evaluateTree(root->left);
        bool rightVal = evaluateTree(root->right);
        return root->val == OR_OP ? leftVal || rightVal : leftVal && rightVal;
    }
};