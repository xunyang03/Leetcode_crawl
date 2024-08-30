class Solution(object):
    def __init__(self):
        self.result = []
    def backtrack(self, k, n, sum, idx, combo):
        if sum > n:
            return
        if len(combo) == k:
            if sum == n:
                self.result.append(combo[:])
                return
        for i in range(idx, 9 - (k - len(combo)) + 2):
            combo.append(i)
            sum += i
            self.backtrack(k, n, sum, i + 1, combo)
            sum -= i
            combo.pop()
        
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        self.backtrack(k, n, 0, 1, [])
        return self.result
