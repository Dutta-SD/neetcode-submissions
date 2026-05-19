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
public:
    void inOrderTraverse(const TreeNode *root, vector<int>& traversalList) {
        if (!root) return;
        inOrderTraverse(root->left, traversalList);
        traversalList.push_back(root->val);
        inOrderTraverse(root->right, traversalList);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodeTraversalList;
        if (!root) return nodeTraversalList;
        inOrderTraverse(root, nodeTraversalList);
        return nodeTraversalList;
    }
};