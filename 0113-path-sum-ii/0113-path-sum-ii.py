# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        self.allpath_ = []
        self.path_ = []
    def findPath(self, node, rest):
        if node is None:
            return
        self.path_.append(node.val)
        if node.left is None and node.right is None and rest == node.val:
            self.allpath_.append(list(self.path_))
        else:
            self.findPath(node.left, rest - node.val)
            self.findPath(node.right, rest - node.val)
        self.path_.pop()
        return
    
    def pathSum(self, root, targetSum):
        """
        :type root: TreeNode
        :type targetSum: int
        :rtype: List[List[int]]
        """
        if root is None:
            return []
        self.findPath(root, targetSum)
        return self.allpath_
        