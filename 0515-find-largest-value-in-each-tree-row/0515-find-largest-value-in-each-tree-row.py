# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = []
        if root == None:
            return []
        def recurse(node, level):
            if node == None:
                return
            if len(result) == level:
                result.append(float('-inf'))
            result[level] = max(result[level], node.val)
            if node.left:
                recurse(node.left, level+1)
            if node.right:
                recurse(node.right, level+1)
        recurse(root, 0)
        return result