# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        gn = 0

        def search_gn(node, max_val):
            nonlocal gn
            if not node:
                return
            if node.val >= max_val:
                gn += 1
                max_val = node.val
            search_gn(node.left, max_val)
            search_gn(node.right, max_val)
        
        search_gn(root, float("-inf"))

        return gn
        