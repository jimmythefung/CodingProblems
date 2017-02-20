class listNode:
    def __init__(self, data):
        self.data = data
        self.next = None

def findJointLL(l1, l2): #l1 is the longer list
     # find length of l1
     len1 = 0
     tmp = l1
     while tmp!=None:
         tmp = tmp.next
         len1 += 1

     # find length of l2
     len2 = 0
     tmp = l2
     while tmp!=None:
         tmp = tmp.next
         len2 += 1
     print len1, len2

     # computer offset
     offset = len1 - len2 # l1 is the longer list

     # move l1 by offset
     for i in range(offset):
         l1 = l1.next

     # step through both list til merge point
     for i in range(len2):
         l1 = l1.next
         l2 = l2.next

         if l1 == l2:
             print "Joint:", l1.data
             return l1
            
         
     

def printLL(node):
    while node!= None:
        print node.data,
        node = node.next
    print ""

def main():
    L1 = listNode(1)
    L2 = listNode(2)
    L3 = listNode(3)
    L4 = listNode(4)
    L5 = listNode(5)

    LA = listNode('A')
    LB = listNode('B')

    L1.next = L2
    L2.next = L3
    L3.next = L4
    L4.next = L5

    LA.next = LB
    LB.next = L4

    printLL(L1)
    printLL(LA)

    findJointLL(L1, LA)
    
        

if __name__ == "__main__":
    main()
