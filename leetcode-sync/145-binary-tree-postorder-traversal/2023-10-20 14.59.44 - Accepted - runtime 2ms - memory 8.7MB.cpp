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

    void postOrderTraverse(const TreeNode *root, vector<int>& traversalList) {
        if (!root) return;
        postOrderTraverse(root->left, traversalList);
        postOrderTraverse(root->right, traversalList);
        traversalList.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodeTraversalList;
        if (!root) return nodeTraversalList;
        postOrderTraverse(root, nodeTraversalList);
        return nodeTraversalList;
    }
};