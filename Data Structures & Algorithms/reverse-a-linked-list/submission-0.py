# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        dummy = None
        a = head
        b = head.next

        while b is not None:
            # print(f"{a.val}, {b.val if b is not None else None}")

            tmp = b
            b = b.next
            tmp.next = a
            a.next = dummy
            dummy = a
            a = tmp

        return a
