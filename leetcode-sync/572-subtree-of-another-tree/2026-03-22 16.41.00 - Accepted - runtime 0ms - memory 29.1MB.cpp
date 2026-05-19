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
    bool isSubTreeMatch(TreeNode* root, TreeNode* subRoot) {
        if (!root || !subRoot)
            return root == subRoot;

        if (root->val == subRoot->val)
            return isSubTreeMatch(root->left, subRoot->left) &&
                   isSubTreeMatch(root->right, subRoot->right);

        return false;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return false;
        if (!subRoot)
            return true;
        if (isSubTreeMatch(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};