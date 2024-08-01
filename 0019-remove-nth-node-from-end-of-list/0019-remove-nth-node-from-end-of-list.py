# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        v_head = ListNode(0, head)
        slow = fast = v_head
        for i in range(n+1):
            if fast == None:
                return v_head.next
            fast = fast.next

        
        while fast != None:
            fast = fast.next
            slow = slow.next
        
        slow.next = slow.next.next
        return v_head.next
