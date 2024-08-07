"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution(object):
    def postorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        vec = []
        def recurse(node):
            if node is None:
                return
            for child in node.children:
                recurse(child)
            vec.append(node.val)
        recurse(root)
        return vec
        