# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        q = deque()
        q.append(root)
        res = []

        while q:
            gen_len = len(q)
            gen_arr = []
            while gen_len:
                gen_len -= 1
                node = q.popleft()
                if node:
                    gen_arr.append(node.val)
                    q.append(node.left)
                    q.append(node.right)
            if gen_arr:
                res.append(gen_arr)

        return res

            

        