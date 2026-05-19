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

    string inOrderTraversalString(TreeNode* node) {
        if (node == nullptr){
            return "N";
        }
        return to_string(node -> val) +
        inOrderTraversalString(node -> left) + 
        inOrderTraversalString(node -> right);
    }

    string inOrderTraversalStringSwitched(TreeNode* node) {
        if (node == nullptr){
            return "N";
        }
        return to_string(node -> val) + inOrderTraversalStringSwitched(node -> right) + 
        inOrderTraversalStringSwitched(node -> left);
    }


    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        if (root -> left == nullptr && root -> right == nullptr) return true;

        return inOrderTraversalString(root -> left) == inOrderTraversalStringSwitched(root -> right);
    }
};