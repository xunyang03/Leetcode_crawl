# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        left_tree = root.left
        right_tree = root.right
        leftDepth = 0
        rightDepth = 0
        while left_tree:
            left_tree = left_tree.left
            leftDepth += 1
        while right_tree:
            right_tree = right_tree.right
            rightDepth += 1
        if leftDepth == rightDepth:
            return 2**(leftDepth+1) - 1
        return self.countNodes(root.left) + self.countNodes(root.right) + 1