## Definition for singly-linked list:
class ListNode(object):
    def __init__(self, x):
        self.value = x
        self.next = None

def buildList(arr):
    # Initialize first element
    L = ListNode(arr[0])
    L.next = None

    # Append the reset to list
    arr = arr[1:]
    p = L
    for x in arr:
        n = ListNode(x)
        p.next = n
        p = n
    p.next = None
    return L

def printLL(L):
    p = L
    while p!=None:
        print(p.value, end=" ")
        p = p.next
    print("\n")
        
def removeKFromList(l, k):
    head = ListNode(-1)
    head.next = l
    
    a = head
    b = head.next
    # Loop invariant: b is the node to be processed; a immediately precedes b.
    while b != None:
        if b.value == k:
                a.next = b.next
                b = a.next
        else:
            a = b
            b = b.next

    return head.next

# Construct list
arr = [3, 1, 2, 3, 4, 5]
k = 3
L = buildList(arr)
printLL(L)

# Remove k from L
L = removeKFromList(L,k)
printLL(L)
