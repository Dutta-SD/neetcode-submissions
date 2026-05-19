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
    void traverse(const TreeNode *root, vector<int>& traversalList) {
        if (!root) return;
        traversalList.push_back(root->val);
        traverse(root->left, traversalList);
        traverse(root->right, traversalList);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodeTraversalList;
        if (!root) return nodeTraversalList;
        traverse(root, nodeTraversalList);
        return nodeTraversalList;
    }
};