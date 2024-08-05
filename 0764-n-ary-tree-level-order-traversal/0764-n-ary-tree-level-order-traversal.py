"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: Node
        :rtype: List[List[int]]
        """
        result = []
        if root == None:
            return []
        def levelrecurs(node, level):
            if node == None:
                return
            if len(result) == level:
                result.append([])
            result[level].append(node.val)
            for child in node.children:
                if child:
                    levelrecurs(child, level+1)
        levelrecurs(root, 0)
        return result
        