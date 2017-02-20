def main():
    G = {0:[3],
         1:[3,4],
         2:[4,7],
         3:[5,6,7],
         4:[6],
         5:[],
         6:[],
         7:[]}
    buildDependency(G)

def buildDependency(G):
    builtSet = set()
    for node in G:
        buildDependencyHelper(node, G, builtSet)
        
def buildDependencyHelper(givenNode, G, builtSet):
    if givenNode in builtSet:
        return
    elif len(G[givenNode])==0:
        print givenNode
        builtSet.add(givenNode)
        return
    else:
        for nextNode in G[givenNode]:
            buildDependencyHelper(nextNode, G, builtSet)

        print givenNode
        builtSet.add(givenNode)


if __name__ == "__main__":
    main()
