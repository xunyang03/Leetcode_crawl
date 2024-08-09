# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        leftSum = self.sumOfLeftLeaves(root.left)
        rightSum = self.sumOfLeftLeaves(root.right)
        if root.left and root.left.left is None and root.left.right is None:
            return root.left.val + rightSum
        return leftSum + rightSum