# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None:
            return 0
        depth = []
        def recurse(node, level):
            if node == None:
                return
            if len(depth) == level:
                depth.append(1)
            recurse(node.left, level+1)
            recurse(node.right, level+1)
        recurse(root, 0)
        return len(depth)