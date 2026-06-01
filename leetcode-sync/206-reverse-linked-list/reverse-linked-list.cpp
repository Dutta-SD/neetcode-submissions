/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head->next))
            return head;
            
        ListNode* x = head;
        ListNode* y = head->next;
        ListNode* temp;

        x->next = nullptr;

        while (y) {
            temp = y->next;
            y->next = x;
            x = y;
            y = temp;
        }

        return x;
    }
};