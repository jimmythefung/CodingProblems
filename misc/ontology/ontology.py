# Quora Challenge: Ontology
# Solution by    : Jimmy Fung
# Contact        : cf2513@columbia.edu
# Date           : Nov 25, 2016

from collections import deque

class ontologyNode:
    def __init__(self, data):
        self.value = data
        self.desc = dict()
        self.myTRIE = dict()

    def addTRIE(self, question):
        getCount = "getCount"
        TRIE_level = self.myTRIE
        for char in question:
            # getCount keeps track of number of leaves at current TRIE, including duplicated questions
            if getCount not in TRIE_level:
                TRIE_level[getCount] = 1
            else:
                TRIE_level[getCount] +=1
            TRIE_level = TRIE_level.setdefault(char, dict())
        if getCount not in TRIE_level:
            TRIE_level[getCount] = 1
        else:
            TRIE_level[getCount] += 1

    def countTRIE(self, query):
        getCount = "getCount"
        d = self.myTRIE

        # Traverse the TRIE path of the query
        for char in query:
            if char in d:
                d = d[char]
            else:
                return 0
            
        # Count the number of leaves contained by the current TRIE node
        return d[getCount]


def ontologyCount(glossary, topic, query, cache):
    q = deque()
    totalCount = 0
    
    #BFS flat tree to sum counts
    if topic not in glossary:
        return 0
    else:
        q.append(glossary[topic])
        while len(q)!=0:
            node = q.popleft()

            if (node.value, query) in cache:
                totalCount += cache[(node.value, query)]
                #print (node.value, query)
            else:
                totalCount += node.countTRIE(query)
                for descTopic in node.desc:
                    q.append(glossary[descTopic])

        cache[(topic, query)] = totalCount
        return totalCount
    
def parseFlatTree(s):
    flatTree = s.split(" ")
    pStack = []
    tmpStack = []
    glossary = dict()
    for e in flatTree:
        if e != ")":
            if e == "(":
                pStack.append(e)
            else:
                glossary[e] = ontologyNode(e)
                pStack.append(glossary[e])
        else:
            while pStack[-1] != "(":
                tmpStack.append( pStack.pop() )
            pStack.pop() # pop "("
            n = pStack.pop()
            while len(tmpStack)!=0:
                tmp = tmpStack.pop()
                n.desc[tmp.value]=tmp
            pStack.append(n)
    return glossary

def main():
        
    lineNum = 1

    # line 1: Interger N
    #print "line 1"
    N = int(raw_input())
    lineNum += 1

    # line 2: N topics arranged in flat tree
    #print "line 2"
    topicFlatTree = raw_input()
    glossary = parseFlatTree(topicFlatTree)
    lineNum += 1


    # line 3: Integer M
    #print "line 3"
    M = int(raw_input())
    lineNum += 1


    # line 4 to M+3: Questions: Topic name followed by a colon and a space
    #print "line 4 to M+3"
    MPairs = []
    while lineNum <= M+3:
        Mline = raw_input()
        Mline = Mline.split(": ")
        glossary[Mline[0]].addTRIE(Mline[1])
        lineNum += 1        


    # line M+4: Integer K
    #print "line M+4"
    K = int(raw_input())
    lineNum += 1


    # line M+5 to (M+K+4): Query: A topic name, followed by a space, and then the query text.
    #print "line M+5 to M+K+4"
    KPairs = []
    cache = dict()
    while lineNum <= M+K+4:
        Kline = raw_input()
        Kline = Kline.split(" ")
        topic = Kline[0]
        query = " ".join(Kline[1:])
        print ontologyCount(glossary, topic, query, cache)
        lineNum += 1

if __name__ == "__main__":
    main()
