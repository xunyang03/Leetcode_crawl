# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        self.vec = []

    def inorder(self, node):
        if node is None:
            return
        self.inorder(node.left)
        self.vec.append(node.val)
        self.inorder(node.right)

    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.inorder(root)
        ans = float('inf')
        for i in range(1, len(self.vec)):
            ans = min(ans, abs(self.vec[i] - self.vec[i-1]))
        return ans
        