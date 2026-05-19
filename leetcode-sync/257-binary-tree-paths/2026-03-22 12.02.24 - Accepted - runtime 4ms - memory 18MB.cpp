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
    const string SEP = "->";
    vector<string> allPaths;

    void addToPaths(TreeNode* node, string pathTraversed) {
        string pathWithCurrentNode =
            (pathTraversed.size() ? pathTraversed + SEP : "") +
            to_string(node->val);

        if (!node->left && !node->right) {
            // Leaf
            allPaths.push_back(pathWithCurrentNode);
            return;
        }
        if (node->left)
            addToPaths(node->left, pathWithCurrentNode);
        if (node->right)
            addToPaths(node->right, pathWithCurrentNode);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        addToPaths(root, "");
        return allPaths;
    }
};