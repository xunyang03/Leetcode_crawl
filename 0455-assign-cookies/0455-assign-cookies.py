class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        result = 0
        g.sort()
        s.sort()
        n_childen = len(g)
        n_cookies = len(s)
        for i in range(0, n_cookies):
            if result < n_childen and g[result] <= s[i]:
                result += 1
        return result