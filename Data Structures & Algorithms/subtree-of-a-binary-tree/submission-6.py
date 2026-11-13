class Solution:
    def isSubtree(self, root, subRoot, match=False) -> bool:
        if not subRoot:
            return (not root) if match else True
        if not root:
            return False
        exact = (
            root.val == subRoot.val
            and self.isSubtree(root.left, subRoot.left, True)
            and self.isSubtree(root.right, subRoot.right, True)
        )
        if exact:
            return True
        if match:
            return False
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)
