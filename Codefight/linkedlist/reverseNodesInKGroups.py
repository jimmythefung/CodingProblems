# Definition for singly-linked list:
# class ListNode(object):
#   def __init__(self, x):
#     self.value = x
#     self.next = None
#
from listDS import *
def reverseNodesInKGroups(l, k):
    # Base cases
    if k==0 or k==1:
        return l
    
    sentinel = ListNode(-1)
    sentinel.next = l
    prv = sentinel
    cur = l
    end = l
    nxt = l
    flag = False
    while True:
        # Advcance end
        for i in range(k-1):
            end = end.next
            if end==None:
                flag=True
                break
                
        # Just connect previous segment to current segment, which is not reversed
        if flag==True:
            prv.next = cur
            break

        # Reverse k group
        nxt = end.next
        reverseLL(cur, end)

        # Connect last segment to current segment
        prv.next = end

        # Restore loop invariant
        prv = cur
        cur = nxt
        end = nxt

        # Edge case: cur==None
        if cur==None:
            break

    return sentinel.next
    

def reverseLL(start, end):
    sentinel = ListNode(-1)
    sentinel.next = start
    
    prv = sentinel
    cur = start
    nxt = start
    
    while cur != end:
        # Advance nxt
        nxt = cur.next
        
        # Reverse node
        cur.next = prv
        
        # Restore loop invariant
        prv = cur
        cur = nxt
    cur.next = prv
    start.next = None

arr = [1,2,3,4]
LL = buildList(arr)
printLL(LL)

end = LL
while end.next != None:
    end = end.next
    

k=2
LL = reverseNodesInKGroups(LL, k)
printLL(LL)
#reverseLL(LL, end)
#printLL(end)
