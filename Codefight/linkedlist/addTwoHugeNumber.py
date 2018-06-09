# Definition for singly-linked list:
# class ListNode(object):
#   def __init__(self, x):
#     self.value = x
#     self.next = None
#
def addTwoHugeNumbers(a, b):
    aVal = 0
    bVal = 0
    
    # Sum to total of a
    p = a
    while p!=None:
        aVal = aVal*10000 + p.value
        p = p.next
    
    # Sum to total of b
    p = b
    while p!=None:
        bVal = bVal*10000 + p.value
        p = p.next
    
    # Sum a + b
    result = aVal + bVal
    s = str(result)
    
    # Slice segments of length 4 into stack starting from the back
    stack = []
    while len(s) > 4:
        x = int( s[-4:] ) # Extract last 4 
        stack.append(x)
        s = s[:-4] # Truncate out last 4
    stack.append( int(s) ) 
    
    # Construct linked list
    n = ListNode(-1)
    sentinel = n
    while len(stack)!=0:
        n.next = ListNode( stack.pop() )
        n = n.next
    return sentinel.next
