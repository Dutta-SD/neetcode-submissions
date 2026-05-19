/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    vector<Node*> nodes = vector<Node*>(101, nullptr);

    Node* clone(Node* node) {
        if (!node)
            return nullptr;

        if (nodes[node->val])
            return nodes[node->val];

        Node* clone_node = new Node(node->val, {});
        nodes[node->val] = clone_node;

        for (auto nb : node->neighbors) {
            (clone_node->neighbors).emplace_back(clone(nb));
        }

        return clone_node;
    }

public:
    Node* cloneGraph(Node* node) { return clone(node); }
};