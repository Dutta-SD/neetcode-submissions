"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:

    def clone(self, node: Node) -> Node:
        if node.val in self.new_nodes:
            return self.new_nodes[node.val]

        n = Node()
        n.val = node.val
        self.new_nodes[node.val] = n
        for nb in node.neighbors:
            n.neighbors.append(self.clone(nb))
        return n

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        self.new_nodes = {}
        
        return self.clone(node)
        
