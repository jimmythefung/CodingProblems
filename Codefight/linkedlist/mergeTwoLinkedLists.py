# Definition for singly-linked list:
# class ListNode(object):
#   def __init__(self, x):
#     self.value = x
#     self.next = None
#
def mergeTwoLinkedLists(l1, l2):
    if l1==None:
        return l2
    if l2==None:
        return l1
    
    sentinel = ListNode(-1)
    n = sentinel
    
    while l1!=None and l2!=None:
        if l1.value < l2.value:
            n.next = l1
            l1 = l1.next
        else:
            n.next = l2
            l2 = l2.next
        n = n.next
    
    if l1==None:
        n.next = l2
    else:
        n.next = l1
    
    return sentinel.next
    
