class treeNode:
    def __init__(self, x):
        self.data = x
        self.left = None
        self.right = None

def minTree(A):
    if len(A)==0:
        return None

    m = len(A)/2

    newNode = treeNode(A[m])
    newNode.left = minTree(A[:m])
    newNode.right = minTree(A[m+1:])

    return newNode

def inOrderDFS(tree, visitfunction):
    if tree != None:
        inOrderDFS(tree.left, visitfunction) # visit left subtree
        visitfunction(tree)                  # visit current node
        inOrderDFS(tree.right, visitfunction)# visit right subtree
    
def printNode(node):
    print node.data, 


def printTree(tree):
    inOrderDFS(tree, printNode)

def isBalanced(root):
    if root == None:
        return 0

    L = isBalanced(root.left)
    R = isBalanced(root.right)

    if abs(L-R)>1 or L<0 or R<0:
        return -1

    return 1 + max(L,R)

def checkBalance(tree):
    return False if (isBalanced(tree)==-1) else True

def listOfDepth(root):
    depth = -1
    q = []
    q.append(root)
    resultLL = []
    while len(q)!=0:
        depth += 1 # not used
        L = []
        while len(q)!=0:
            L.append(q.pop())
        resultLL.append(L)
        q = getNextLevel(L)

    # print list
    depth = 0
    for L in resultLL:
        print "Depth "+str(depth)+": ",
        for node in L:
            print node.data,
        print "\n"
        depth += 1
    # end of print list
    
    return resultLL

def getNextLevel(listOfNodes):
    L = listOfNodes[:]
    q = []
    while len(L)!=0:
        n = L.pop()
        if n.left != None:
            q.append(n.left)
        if n.right != None:
            q.append(n.right)
    return q

A = [0,1,2,3,4,5,6,7,8,9]
t = minTree(A)
printTree(t)
print "is balanced?", checkBalance(t)

n = treeNode(33)
n.right = treeNode(34)
n.left = t
printTree(n)
print "is balanced?", checkBalance(n)

listOfDepth(n)
