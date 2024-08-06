"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution(object):
    def connect(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        nodeprev = []
        def recurse(node, level):
            if node == None:
                return
            if len(nodeprev) == level:
                nodeprev.append(Node())
            nodeprev[level].next = node
            nodeprev[level] = nodeprev[level].next
            recurse(node.left, level+1)
            recurse(node.right, level+1)
        recurse(root, 0)
        return root
        