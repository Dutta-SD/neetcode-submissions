/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root)
            return {};
        vector<int> traversal;
        traversal.push_back(root->val);

        for (Node* ch : root->children) {
            vector<int> c_traversal = preorder(ch);
            traversal.insert(traversal.end(), c_traversal.begin(),
                             c_traversal.end());
        }
        return traversal;
    }
};