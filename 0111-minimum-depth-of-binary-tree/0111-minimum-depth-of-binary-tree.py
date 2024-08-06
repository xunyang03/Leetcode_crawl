# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        def recurse(node):
            if node is None:
                return float('inf')
            if node.left is None and node.right is None:
                return 1
            left_depth = recurse(node.left)
            right_depth = recurse(node.right)
            return min(left_depth, right_depth) + 1

        return recurse(root)