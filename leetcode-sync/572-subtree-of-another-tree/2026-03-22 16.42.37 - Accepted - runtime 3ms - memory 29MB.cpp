#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

        return (root->val == subRoot->val) &&
               isSubTreeMatch(root->left, subRoot->left) &&
               isSubTreeMatch(root->right, subRoot->right);
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