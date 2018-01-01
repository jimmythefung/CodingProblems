# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        return swapPairsHelper(head)

def swapPairsHelper(head):
    
    # Case Length <= 1
    if head == None:
        return head
    if head.next == None:
        return head

    # Case 2: Length >= 2
    else:
        n = head.next
        last = head
        head = n        # n is the second node in the linked list, and will become head.

        i = 2
        Llast = ListNode(None) # Sentinel node
        while n != None:
            if i%2 == 0:
                n1 = n.next
                
                # Perform swap
                last.next = n1
                n.next = last
                Llast.next = n

                # n and last were reversed as side effect of swap; restore the order
                last = n
                n = n.next
            else:
                Llast = last

            # Prepare for next iteration by moving all pointer 1 up
            last = last.next
            n = n.next
            i += 1
        return head

def oneSwap(a, b, c):
    b.next = a
    a.next = c
    return b
