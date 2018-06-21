import sys
import os
sys.path.append(os.path.abspath("../"))
from binaryTree import *
#
# Definition for binary tree:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None
from collections import deque
def isTreeSymmetric(t):
    # Base case
    if t == None:
        return True

    Q = deque()
    Q.append( t )
    l = 1
    v = []
    # Loop Invariant: l is length of queue, val is empty use to store child level values    
    while len(Q) != 0:
        for i in range(l):
            n = Q.popleft()
            # Left
            if n.left != None:
                Q.append(n.left)
                v.append(n.left.value)
            else:
                v.append(" ")
                
            # Right
            if n.right != None:
                Q.append(n.right)
                v.append(n.right.value)
            else:
                v.append(" ")

        # Check palindrome
        if arrIsPalindrome(v) != True:
            return False

        # Restore loop invariant
        l = len(Q)
        v = []

    return True

def arrIsPalindrome( arr ):
    # Base case
    if len(arr) <= 1:
        return True
    l = 0
    r = len(arr)-1
    while l < r:
        if arr[l] != arr[r]:
            return False
        l += 1
        r -= 1
    return True
