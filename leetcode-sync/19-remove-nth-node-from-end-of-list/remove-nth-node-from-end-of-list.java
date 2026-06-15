/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int N = n + 1;
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode fast = dummy;

        while (fast != null && N > 0) {
            fast = fast.next;
            N = N - 1;
        }

        if (N > 0) {
            return head;
        }

        ListNode slow = dummy;

        while (fast != null) {
            slow = slow.next;
            fast = fast.next;
        }

        if (slow.next != null) {
            slow.next = slow.next.next;
        }

        return dummy.next;
    }
}