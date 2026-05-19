# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        num = ListNode()
        head = num
        
        while l1 != None and l2 != None:
            s = l1.val + l2.val + carry
            d = s % 10
            carry = s // 10
            num.next = ListNode(d)
            num = num.next
            l1 = l1.next
            l2 = l2.next
        
        while l1 != None:
            s = l1.val + carry
            d = s % 10
            carry = s // 10
            num.next = ListNode(d)
            num = num.next
            l1 = l1.next
            
        while l2 != None:
            s = l2.val + carry
            d = s % 10
            carry = s // 10
            num.next = ListNode(d)
            num = num.next
            l2 = l2.next
            
        if carry:
            num.next = ListNode(carry)
        
        head = head.next
        return head
            
        
            
        
        