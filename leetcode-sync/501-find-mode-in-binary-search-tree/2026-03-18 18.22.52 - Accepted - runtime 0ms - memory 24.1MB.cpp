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
    int previousValue = INT_MIN;
    int maxCount = INT_MIN;
    int currentCount = 0;
    vector<int> modes;
    
public:
    void updateValue(const int x) {
        if (x == previousValue) currentCount++;
        else {
            currentCount = 1;
            previousValue = x;
        }

        if (currentCount == maxCount) {
            modes.push_back(x);
        }
        if (currentCount > maxCount) {
            modes.clear();
            maxCount = currentCount;
            modes.push_back(x);
        }
    }


    void traverseTree(TreeNode* root) {
        if (root == nullptr) return;
        traverseTree(root -> left);
        updateValue(root->val);
        traverseTree(root -> right);
    }

    vector<int> findMode(TreeNode* root) {
        traverseTree(root);
        return modes;
    }
};