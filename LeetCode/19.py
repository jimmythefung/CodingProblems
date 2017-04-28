##Given linked list: 1->2->3->4->5, and n = 2.
##After removing the second node from the end, the linked list becomes 1->2->3->5.

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        return remove(head, n)

def remove(head, offset):
    sent = ListNode(-1)
    sent.next = head
    nodeM = sent
    nodeN = head
    offsetNode = head
    for i in range(1, offset):
        offsetNode = offsetNode.next
    while offsetNode.next != None:
        nodeM = nodeN
        nodeN = nodeN.next
        offsetNode = offsetNode.next

    nodeM.next = nodeN.next
    return sent.next

l = ListNode(1)
l2 = ListNode(2)
l.next = l2
l = remove(l,1)
print l.val
print l.next
