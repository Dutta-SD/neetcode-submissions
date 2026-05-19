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
    int sum = 0;

    bool isLeaf(const TreeNode* node) {
        return !node -> left && !node ->right;
    }

    void aggLeftLeaves(TreeNode* node) {
        if (!node) return;
        if (node -> left && isLeaf(node -> left)) {
            sum += node -> left -> val;
        }
        if (node -> left) aggLeftLeaves(node -> left);
        if (node -> right) aggLeftLeaves(node -> right);
    }


public:
    int sumOfLeftLeaves(TreeNode* root) {
        aggLeftLeaves(root);
        return sum;
    }
};