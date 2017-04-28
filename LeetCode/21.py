# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        return merge(l1, l2)

        
def merge(l1, l2):
    if l1==None:
        return l2
    if l2==None:
        return l1
    head = l1
    while l1 != None:
        x = l1.next
        y = l2.next
        l1.next = l2
        l2.next = x
        l1 = x
        l2 = y
    return head

l1 = ListNode(1)
a = ListNode(3)
b = ListNode(5)
a.next=b
l1.next=a

l2 = ListNode(0)
