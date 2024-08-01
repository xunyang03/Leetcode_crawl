class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        slow = 0
        for fast in nums:
            if fast != val:
                nums[slow] = fast
                slow += 1
        return slow
        