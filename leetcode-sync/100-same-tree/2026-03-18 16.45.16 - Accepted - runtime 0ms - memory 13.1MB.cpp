class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(p);
        q2.push(q);

        while(!q1.empty() && !q2.empty())
        {
            TreeNode* cur1 = q1.front();
            TreeNode* cur2 = q2.front();

            q1.pop();
            q2.pop();

            if(cur1 == nullptr && cur2 == nullptr)
            {
                continue;
            }
            if(cur1 == nullptr || cur2 == nullptr) return false;
            if(cur1->val != cur2->val) return false;

            q1.push(cur1->left);
            q2.push(cur2->left);
            q1.push(cur1->right);
            q2.push(cur2->right);
        }
        return true;
    }
};