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
        levelhead = []
        def recurse(node, level):
            if node == None:
                return
            if len(levelhead) == level:
                prev = Node(0, None, None, None)
                levelhead.append(prev)
            levelhead[level].next = node
            levelhead[level] = levelhead[level].next
            if node.left:
                recurse(node.left, level+1)
            if node.right:
                recurse(node.right, level+1)
        recurse(root, 0)
        return root