# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def getHeight(self, node):
        if node is None:
            return 0
        leftH = self.getHeight(node.left)
        rightH = self.getHeight(node.right)
        if leftH == -1 or rightH == -1 or abs(leftH - rightH) > 1:
            return -1
        return max(leftH, rightH) + 1
    
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.getHeight(root) != -1
        