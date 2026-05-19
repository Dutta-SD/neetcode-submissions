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
private:
    const string SEP = "->";
    const string EMPTY_STRING = "";
    vector<string> allPaths;

    void addToPaths(TreeNode* node, string pathTraversed) {
        string pathWithCurrentNode =
            (pathTraversed.size() ? pathTraversed + SEP : EMPTY_STRING) +
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
        addToPaths(root, EMPTY_STRING);
        return allPaths;
    }
};