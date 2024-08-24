# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        sum

    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        self.sum = 0
        def recurse(root):
            if root is None:
                return root
            root.right = recurse(root.right)
            self.sum += root.val
            root.val = self.sum
            root.left = recurse(root.left)
            return root
        return recurse(root)