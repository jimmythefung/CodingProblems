from listDS import *
# Definition for singly-linked list:
# class ListNode(object):
#   def __init__(self, x):
#     self.value = x
#     self.next = None
#
def isListPalindrome(l):
    arr = []
    while l!=None:
        arr.append( l.value )
        l = l.next

    return isArrPal(arr)

def isArrPal(arr):
    i = 0
    j = len(arr)-1
    while i < j:
        if arr[i] != arr[j]:
            return False
        i+=1
        j-=1
    return True

# Test
a1 = [1,2,3,2,1]
a2 = [1,2,3,3,1]
print( isListPalindrome( buildList(a1) ) )
print( isListPalindrome( buildList(a2) ) )


