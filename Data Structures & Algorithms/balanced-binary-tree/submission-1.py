# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True

        def height(root: TreeNode):
            if root is None:
                return 0
            return 1 + max(height(root.left), height(root.right))

        r = height(root.right)
        l = height(root.left)

        return abs(l - r) <= 1 and self.isBalanced(root.right) and self.isBalanced(root.left)
