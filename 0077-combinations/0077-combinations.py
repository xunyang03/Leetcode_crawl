class Solution(object):
    def __init__(self):
        self.result = []
    
    def backtrack(self, n, k, startIdx, combo):
        if len(combo) == k:
            self.result.append(combo[:])
            return
        for i in range(startIdx, n + 1):
            combo.append(i)
            self.backtrack(n, k, i + 1, combo)
            combo.pop()

    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        self.backtrack(n, k, 1, [])
        return self.result