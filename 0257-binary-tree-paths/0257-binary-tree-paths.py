# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        result = []
        def preorder(node, path):
            path += str(node.val)
            if node.left is None and node.right is None:
                result.append(path)
                return
            if node.left:
                preorder(node.left, path+"->")
            if node.right:
                preorder(node.right, path+"->")
        preorder(root, "")
        return result