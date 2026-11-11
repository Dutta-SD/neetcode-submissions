# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head:
            return False

        slow = head
        fast = head.next

        while fast != slow:
            if fast == None or slow == None:
                return False
            slow = slow.next if slow else None
            fast = fast.next.next if fast.next else None

            if fast == slow:
                return True

        return True
