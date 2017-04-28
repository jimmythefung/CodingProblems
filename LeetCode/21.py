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
	head = l1
	prev = l1
	a1 = l1.next
	b1 = l2
	if l1.val > l2.val:
		return merge(l2, l1)

	while b1!=None:
		while a1.val < b1.val:
			prev = a1
			a1 = a1.next
			if a1==None:
				prev.next = b1
				return head
		prev.next = b1
		b1 = b1.next
		
		prev = a1
		a1 = a1.next
	return head
