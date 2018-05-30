from collections import deque
#
# Definition for binary tree:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None
def traverseTree(t):
    result = []
    if t==None:
        return result
    q = deque()
    q.append(t)

    while len(q) != 0:
        m = len(q)
        for i in range(m):
            # Get node from current level
            n = q.popleft()

            # Process current node
            result.append(n.value)

            # Enqueue next level nodes
            if n.left != None:
                q.append( n.left )
            if n.right != None:
                q.append( n.right )
    return result


import sys
import os
sys.path.append(os.path.abspath("../"))
from binaryTree import *
d = {
    "value": 1,
    "left": {
        "value": 2,
        "left": None,
        "right": {
            "value": 3,
            "left": None,
            "right": None
        }
    },
    "right": {
        "value": 4,
        "left": {
            "value": 5,
            "left": None,
            "right": None
        },
        "right": None
    }
}

t = buildTreeFromDict(d)
print( traverseTree(t) )

