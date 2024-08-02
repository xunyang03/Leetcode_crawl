# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def in_trav(self, root, vec):
        if root is None:
            return
        self.in_trav(root.left, vec)
        vec.append(root.val)
        self.in_trav(root.right, vec)

    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res = []
        self.in_trav(root, res)
        return res

        