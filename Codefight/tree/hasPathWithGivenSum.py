import sys
import os
sys.path.append(os.path.abspath("../"))
from binaryTree import *

# Definition for binary tree:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None
def hasPathWithGivenSum(t, s):
    if t!=None:
        path = []
        result = [False]
        inOrderDFS(t, s, path, result)
        return result[0]
    else:
        return True if s==0 else False

def inOrderDFS(t, s, path, result):

    # Base case: NULL node
    if t==None:
        return

    # Base case: leaf
    if (t.left==None) and (t.right==None):
        path.append(t.value)
        if sum(path) == s:
            result[0] = True
        path.pop()
        return 

    # visit left
    path.append(t.value)
    inOrderDFS(t.left, s, path, result)
    path.pop()

    # visit current; do nothing
    

    # visit right
    path.append(t.value)
    inOrderDFS(t.right, s, path, result)
    path.pop()
