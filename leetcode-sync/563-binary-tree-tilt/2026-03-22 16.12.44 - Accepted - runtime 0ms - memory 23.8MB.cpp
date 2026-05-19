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
    int tiltSum = 0;
    int sumTraverse(TreeNode* node) {
        if (!node)
            return 0;

        int lv, rv;
        lv = sumTraverse(node->left);
        rv = sumTraverse(node->right);

        tiltSum += abs(lv - rv);

        return lv + rv + node->val;
    }

public:
    int findTilt(TreeNode* root) {
        sumTraverse(root);
        return tiltSum;
    }
};