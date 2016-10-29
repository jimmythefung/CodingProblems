G = {0:[3],
     1:[3,4],
     2:[4,7],
     3:[5,6,7],
     4:[6],
     5:[],
     6:[],
     7:[]}


def buildProjects(G):
    builtProjects = set()
    for v in G:
        rbuild(G, v, builtProjects)

def rbuild(G, v, builtProjects):
    if v in builtProjects:
        return

    for dependedNode in G[v]:
        rbuild(G, dependedNode, builtProjects)

    builtProjects.add(v)
    print v


buildProjects(G)
