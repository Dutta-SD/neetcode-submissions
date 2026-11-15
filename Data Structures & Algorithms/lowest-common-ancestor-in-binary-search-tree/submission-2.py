# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def fill_path(self, node, target, path):
        path.append(node)
        if node.val == target:
            return
        if target < node.val:
            self.fill_path(node.left, target, path)
        else:
            self.fill_path(node.right, target, path)

    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        p_p, p_q = [], []
        self.fill_path(root, p.val, p_p)
        self.fill_path(root, q.val, p_q)

        print(f"{[x.val for x in p_p]}")
        print(f"{[x.val for x in p_q]}")

        i = 0
        while i < len(p_p) and i < len(p_q) and p_p[i] == p_q[i]:
            i += 1

        return p_p[i-1]
