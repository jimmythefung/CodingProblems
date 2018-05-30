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
