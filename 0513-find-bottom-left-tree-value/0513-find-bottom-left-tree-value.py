# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        nodeque = [root]
        result = 0
        while (nodeque):
            size = len(nodeque)
            for i in range(size):
                cur = nodeque.pop(0)
                if i == 0:
                    result = cur.val
                if cur.left:
                    nodeque.append(cur.left)
                if cur.right:
                    nodeque.append(cur.right)
        return result