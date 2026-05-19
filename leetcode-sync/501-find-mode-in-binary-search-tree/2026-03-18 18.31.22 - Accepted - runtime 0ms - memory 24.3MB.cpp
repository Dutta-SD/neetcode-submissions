class Solution {
    int currVal = 0;
    int count = 0;
    int maxCount = 0;
    vector<int> modes;

public:
    void handleValue(int val) {
        if (val == currVal) count++;
        else {
            currVal = val;
            count = 1;
        }

        if (count > maxCount) {
            maxCount = count;
            modes.clear();
            modes.push_back(val);
        } else if (count == maxCount) {
            modes.push_back(val);
        }
    }

    vector<int> findMode(TreeNode* root) {
        TreeNode* curr = root;

        while (curr) {
            if (!curr->left) {
                handleValue(curr->val);
                curr = curr->right;
            } else {
                TreeNode* pred = curr->left;

                // find rightmost node
                while (pred->right && pred->right != curr)
                    pred = pred->right;

                if (!pred->right) {
                    // create thread
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    // remove thread
                    pred->right = nullptr;
                    handleValue(curr->val);
                    curr = curr->right;
                }
            }
        }

        return modes;
    }
};