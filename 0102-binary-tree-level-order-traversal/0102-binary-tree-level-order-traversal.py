# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        result = []
        queue = []
        if root:
            queue.append(root)
        while queue:
            cur_level = []
            cur_size = len(queue)
            for i in range(cur_size):
                node = queue.pop(0)                
                cur_level.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            result.append(cur_level)
        return result

    def levelOrder_cursive(self, root):
        if not root:
            return []
        result = []
        def traverse(node, level):
            if not node:
                return
            if len(result) == level:
                result.append([])
            result[level].append(node.val)
            traverse(node.left, level+1)
            traverse(node.right, level+1)
        traverse(root, 0)
        return result

        