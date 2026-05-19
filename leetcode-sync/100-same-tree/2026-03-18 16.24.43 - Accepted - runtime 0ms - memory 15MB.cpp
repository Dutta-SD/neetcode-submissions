class Solution {
public:
    string traversalSignature(TreeNode* node) {
        if (node == nullptr){
            return "N";
        }
        return to_string(node -> val) +
        traversalSignature(node -> left) + 
        traversalSignature(node -> right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return traversalSignature(p) == traversalSignature(q);
    }
};