# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        int1 = 0
        int2 = 0
        exp = 0
        while l1!=None:
            int1 = int1 + l1.val*(10**exp)
            l1 = l1.next
            exp +=1
        exp = 0
        while l2!=None:
            int2 = int2 + l2.val*(10**exp)
            l2 = l2.next
            exp +=1
        
        mySum = str(int1 + int2)
        
        # build output
        result = ListNode(mySum[-1])
        i = len(mySum)-2
        p = result
        while i >= 0:
            p.next = ListNode(mySum[i])
            p = p.next
            i -=1
        
        return result
        
