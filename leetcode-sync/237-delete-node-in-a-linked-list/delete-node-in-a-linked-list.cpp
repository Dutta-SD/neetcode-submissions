/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* curr = node->next;

        while (curr->next) {
            node->val = curr->val;
            node = curr;
            curr = curr->next;
        }

        node->val = curr->val;
        node->next = nullptr;
    }
};