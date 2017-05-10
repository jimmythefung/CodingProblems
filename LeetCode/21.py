# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

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
    sentinel = ListNode('sentinel')
    pre = sentinel
    # loop invariant precoditions
    p1 = l1
    p2 = l2
    while p1!=None and p2!=None:
        if p1.val < p2.val:
            pre.next = p1
            pre = pre.next
            p1 = p1.next
        else:
            pre.next = p2
            pre = pre.next
            p2 = p2.next

        if p1==None:
            pre.next = p2
        if p2==None:
            pre.next = p1
    return sentinel.next


l1 = ListNode(1)
a = ListNode(3)
b = ListNode(5)
a.next=b

# test
l1.next=a
l2 = ListNode(0)
l3 = merge(l1, l2)
