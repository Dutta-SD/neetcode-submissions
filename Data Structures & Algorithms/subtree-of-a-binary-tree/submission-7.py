class Solution:
    def isSubtree(self, root, subRoot, must_match_exactly=False) -> bool:
        if not subRoot:
            return (not root) if must_match_exactly else True
        if not root:
            return False
        exact = (
            root.val == subRoot.val
            and self.isSubtree(root.left, subRoot.left, True)
            and self.isSubtree(root.right, subRoot.right, True)
        )
        if exact:
            return True
        if must_match_exactly:
            return False
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)
