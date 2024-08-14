# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        self.vec = []
    def inorder(self, root):
        if root is None:
            return
        self.inorder(root.left)
        self.vec.append(root.val)
        self.inorder(root.right)
        return

    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None:
            return True
        self.inorder(root)
        for i in range(1,len(self.vec)):
            if self.vec[i] <= self.vec[i-1]:
                return False
        return True