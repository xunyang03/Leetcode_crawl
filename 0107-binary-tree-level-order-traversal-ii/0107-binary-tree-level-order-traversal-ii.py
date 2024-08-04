# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        result  = []
        def traverse(node, level):
            if not node:
                return
            if len(result) == level:
                result.append([])
            traverse(node.left, level+1)
            traverse(node.right, level+1)
            result[level].append(node.val)
        traverse(root, 0)
        
        return reversed(result)