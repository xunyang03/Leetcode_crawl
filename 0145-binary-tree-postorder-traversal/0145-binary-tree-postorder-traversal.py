# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res = []
        def post_trav(root):
            if root is None:
                return
            post_trav(root.left)
            post_trav(root.right)
            res.append(root.val)
        post_trav(root)
        return res
        