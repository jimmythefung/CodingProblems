from collections import deque
# Definition for binary tree:
class Tree(object):
    def __init__(self, x):
        self.value = x
        self.left = None
        self.right = None

def buildTreeFromDict(d):
    # Base case
    if d == None:
        return None
    
    # visit left
    nL = None
    if 'left' in d:
        nL = buildTreeFromDict(d['left'])

    # visit current
    n = Tree(d['value'])

    # visit right
    nR = None
    if 'right' in d:
        nR = buildTreeFromDict(d['right'])

    n.left = nL
    n.right = nR
    return n

def printTree(root):
    q = deque()
    q.append( root )

    while len(q) != 0:
        size = len(q)
        for i in range(size):
            # Extract node
            n = q.popleft()

            # Process node
            print(n.value, end=" ")

            # Enqueue child nodes
            if n.left != None:
                q.append( n.left )
            if n.right != None:
                q.append( n.right )
        print(" ")

def getExampleTree():
    d = {
        "value": 4,
        "left": {
            "value": 1,
            "left": {
                "value": -2,
                "left": None,
                "right": {
                    "value": 3,
                    "left": None,
                    "right": None
                }
            },
            "right": None
        },
        "right": {
            "value": 3,
            "left": {
                "value": 1,
                "left": None,
                "right": None
            },
            "right": {
                "value": 2,
                "left": {
                    "value": -2,
                    "left": None,
                    "right": None
                },
                "right": {
                    "value": -3,
                    "left": None,
                    "right": None
                }
            }
        }
    }

    return buildTreeFromDict(d)

