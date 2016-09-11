from random import randint
from collections import deque
# improve by recursion and dynamic programming (cache tallest height seen as boxes build up)
class tNode:
    def __init__(self, x):
        self.data = x
        self.L = None
        self.R = None
        

class bst:
    def __init__(self):
        self.root = None
        self.boxHeight = 0

    def insertBox(self, boxArr):
        for box in boxArr:
            #print "Inserting:", box
            self.rInsert(self.root, box)
            #self.insert(box)

    def insert(self, x):
        if self.root == None:
            self.root = tNode(x)
            print "Inserted:", x
            return

        tmp = self.root
        while True:
            cmpV = self.boxCmp(tmp.data, x)
            #print cmpV
            if cmpV == 2:
                if tmp.R == None:
                    tmp.R = tNode(x)
                    print "Inserted:", x
                    break
                else:
                    tmp = tmp.R
            elif cmpV == 1:
                if tmp.L == None:
                    tmp.L = tNode(x)
                    print "Inserted:", x
                    break
                else:
                    tmp = tmp.L
            else:
                break

            
    def rInsert(self, n, x):
        if self.root == None:
            self.root = tNode(x)
            self.boxHeight += x[2]
            return

        cmpV = self.boxCmp(n.data, x)
        #print cmpV
        if cmpV == 2:
            if n.R != None:
                self.rInsert(n.R, x)
            else:
                n.R = tNode(x)
                self.boxHeight += x[2]
        elif cmpV == 1:
            if n.L != None:
                self.rInsert(n.L, x)
            else:
                n.L = tNode(x)
                self.boxHeight += x[2]
        else:
            return



    def boxCmp(self, box1, box2):
        #print box1, box2
        w1 = box1[0]
        d1 = box1[1]
        h1 = box1[2]
        w2 = box2[0]
        d2 = box2[1]
        h2 = box2[2]
        if (w2 > w1) and (d2 > d1) and (h2 > h1): # box2 bigger
            return 2
        elif (w2 < w1) and (d2 < d1) and (h2 < h1): # box1 bigger
            return 1
        else:                                       # not comparable
            return 0

    def DFS(self, n):
        if n == None:
            return
        self.DFS(n.L)
        print n.data
        self.DFS(n.R)

    def inOrder(self):
        self.DFS(self.root)


        
def box():
    return [randint(1,30), randint(1,30), randint(1,30)]
boxes = deque()
boxes += [box() for i in range(100)]

boxStack = []
boxStackHeight = []
for i in range(len(boxes)):
    print "Building stack with box"+str(i)+" included in solution."
    picked = boxes.popleft()

    t = bst()
    t.insertBox(boxes)

    boxStack.append(t)
    boxStackHeight.append(t.boxHeight)

    t.inOrder()
    print "Stack height:", t.boxHeight

    
    boxes.append(picked)
    print 
    print ""


maxInd = 0
maxSeen = boxStackHeight[0]
for i in range(len(boxStackHeight)):
    if boxStackHeight[i] > maxSeen:
        maxSeen = boxStackHeight[i]
        maxInd = i
    
print "The tallest stack is height:", boxStackHeight[maxInd]
print "Tallest stack makeup:"
boxStack[maxInd].inOrder()
