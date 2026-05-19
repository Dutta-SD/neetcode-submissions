#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
    int maxDepth(Node* root) {
        if (!root)
            return 0;
        int maxDepthChildren = 0;
        for (auto node : root->children) {
            if (node)
                maxDepthChildren = max(maxDepthChildren, maxDepth(node));
        }
        return 1 + maxDepthChildren;
    }
};