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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* ptr = head -> next;
        ListNode* ptr2 = head;

        while (ptr2){
            while (ptr && ptr -> val == ptr2 -> val) {
                ptr = ptr -> next;
            }
            ptr2 -> next = ptr;
            ptr2 = ptr;
        }

        return head;
    }
};