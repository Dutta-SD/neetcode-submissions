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
    public record Pair<S, T>(S first, T second) {
    }

    private ListNode getKthNode(ListNode curr, int k) {
        while (curr != null && k > 1) {
            curr = curr.next;
            k--;
        }
        return curr;
    }

    private Pair<ListNode, ListNode> reverseLLSnippet(ListNode startNode, ListNode endNode) {
        ListNode prev = null;
        ListNode curr = startNode;

        while (prev != endNode) {
            ListNode tmpNode = curr;
            curr = curr.next;
            tmpNode.next = prev;
            prev = tmpNode;
        }

        return new Pair(endNode, startNode);
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || k == 1)
            return head;

        ListNode dummyNode = new ListNode();
        dummyNode.next = head;

        ListNode groupPrevious = dummyNode;
        ListNode groupNext = dummyNode.next;

        while (true) {
            ListNode startNode = groupPrevious.next;
            ListNode kthNode = getKthNode(groupNext, k);

            if (kthNode == null)
                break;
            groupNext = kthNode.next;

            Pair<ListNode, ListNode> rSnippet = reverseLLSnippet(startNode, kthNode);
            ListNode sStart = rSnippet.first();
            ListNode sEnd = rSnippet.second();

            groupPrevious.next = sStart;
            sEnd.next = groupNext;
            groupPrevious = sEnd;
        }

        return dummyNode.next;
    }
}