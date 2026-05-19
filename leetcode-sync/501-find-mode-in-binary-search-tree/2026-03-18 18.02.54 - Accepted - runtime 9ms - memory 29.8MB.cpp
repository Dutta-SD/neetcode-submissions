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
    std::unordered_map<int, int> counts;
    
public:

    void updateCount(const int x){
        if(counts.find(x) != counts.end()) counts[x]++;
        else counts[x] = 1;
    }

    vector<int> calculateModes() {
        int max_count = INT_MIN;
        vector<int> modes;

        for(const auto& pair : counts){
            if(pair.second > max_count) max_count = pair.second;
        }

        for(const auto& pair : counts){
            if(pair.second == max_count) modes.push_back(pair.first);
        }

        return modes;
    }

    void traverseTree(TreeNode* root) {
        if (root == nullptr) return;
        updateCount(root->val);
        traverseTree(root -> left);
        traverseTree(root -> right);
    }

    vector<int> findMode(TreeNode* root) {
        traverseTree(root);
        return calculateModes();
    }
};