# Problem: Given a Binary Tree that exists in Machine 1, copy it and reconstruct it in Machine 2.
class node:
    def __init__(self, x):
        self.data = x
        self.L = None
        self.R = None
        
def encode(n):
    arr = []
    encodeHelper(n, arr)
    return arr

def encodeHelper(n, arr):
    if n==None:
        arr.append(None)
    else:
        # pre-order traversal
        arr.append(n.data)      # visit current
        encodeHelper(n.L, arr)  # visit left
        encodeHelper(n.R, arr)  # visit right

def decode(arr):
    last = [-1]
    tree = decodeHelper(arr, last)
    return tree

def decodeHelper(arr, last):
    last[0] += 1

    if arr[ last[0] ] == None:
        return None
    
    current = node( arr[ last[0] ])

    current.L = decodeHelper(arr, last)
    current.R = decodeHelper(arr, last)
    return current
    

# encode test
l = node("l")
o = node("o")
v = node("v")
e = node("e")
l.L = o
o.L = v
o.R = e
arr = encode(l)
print arr

# decode test
def preOrderPrint(t):
    if t == None:
        return
    print t.data,
    preOrderPrint(t.L)
    preOrderPrint(t.R)
t = decode(arr)
preOrderPrint(t)
