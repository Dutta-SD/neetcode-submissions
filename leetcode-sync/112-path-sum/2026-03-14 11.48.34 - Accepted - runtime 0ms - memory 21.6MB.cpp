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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr){
            return false;
        }
        // Leaf base condition
        if ((root -> left) == nullptr && (root -> right) == nullptr) {
            return (root -> val) == targetSum;
        }

        bool hasLeftSum = false;
        bool hasRightSum = false;

        if (root -> left != nullptr) {
            hasLeftSum = hasPathSum(root -> left, targetSum - (root -> val));
        }

        if (root -> right != nullptr) {
            hasRightSum = hasPathSum(root -> right, targetSum - (root -> val));
        }

        return hasLeftSum || hasRightSum;
        
    }
};