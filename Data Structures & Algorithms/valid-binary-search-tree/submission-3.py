# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

MAX_VAL = float("inf")
MIN_VAL = float("-inf")


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        traversal = []

        def inorder(root):
            if not root:
                return

            inorder(root.left)
            traversal.append(root.val)
            inorder(root.right)

        inorder(root)

        for i in range(1, len(traversal)):
            if traversal[i - 1] >= traversal[i]:
                return False

        return True
