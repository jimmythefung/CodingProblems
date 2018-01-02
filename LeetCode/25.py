class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        return reverseGroup(head, k)

def reverseGroup(head, k):
    if head==None or head.next==None or k<=1:
        return head
    
    # Partition into segments
    partitions = partByGroup(head, k)

    # Reverse each segments
    i=0
    for p in partitions:
        if getSize(p)==k:
            partitions[i] = reverse( p )
        i+=1

    # Join back all segments
    i=1
    while i < len(partitions):
        partitions[i-1][1].next = partitions[i][0] # connect prev's end to current begin
        i += 1

    # head is the first value in the first partition
    return partitions[0][0]
        
def reverse( p ):
    n = p[0]
    end = p[1]

    if n == None or n.next == None:
        return p
    
    # Initialization satisfying invariant
    prev = n
    n = n.next
    prev.next = None
    head = prev
    
    # Loop invariant: prev is disconnected to current node
    while n != end and n.next!=None:
        nxt = n.next
        n.next = prev
        prev = n
        n = nxt

    n.next = prev
    return [n, head]

def partByGroup(head, k):
    result = []
    n = head
    while n != None:
        start = n
        counter = 1
        while counter < k and n.next != None:
            n = n.next
            counter += 1

        result += [[start, n]]

        # prepare loop invariant
        n = n.next
        counter = 1
    return result
    

def getSize(p):
    head = p[0]
    end = p[1]
    if head == None:
        return 0
    size = 1
    n = head
    while n.next!= None and n!=end:
        n = n.next
        size += 1
    return size

## -- testing -- ##
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

def createList():
    n1 = ListNode(1)
    n2 = ListNode(2)
    n3 = ListNode(3)
    n4 = ListNode(4)
    n5 = ListNode(5)
    n4.next = n5
    n3.next = n4
    n2.next = n3
    n1.next = n2
    return n1


def printList(head):
    n = head
    while n != None:
        print n.val,
        n = n.next
        
l = createList()
l2 = reverseGroup(l, 3)
printList(l2)
