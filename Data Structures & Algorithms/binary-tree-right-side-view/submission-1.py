# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque


class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        q = deque()
        res = []
        q.append(root)

        while q:
            lq = len(q)
            e = None
            for _ in range(lq):
                e = q.popleft()
                if e.left:
                    q.append(e.left)
                if e.right:
                    q.append(e.right)
            res.append(e.val)


        return res

                
        