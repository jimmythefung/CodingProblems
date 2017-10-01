def printBuildOrder(G):
    visited = set()
    helper(G, visited)

def helper(G, visited):
	for topLevelNode in G:
		visitNode(topLevelNode, visited, G)

def visitNode(n, visited, G):
	if n in visited:
		return
	if len(G[n])==0:
		print n
		visited.add(n)
	else:
		for neighbor in G[n]:
			visitNode(neighbor, visited, G)
		print n
		visited.add(n)

G = {}
G['6'] = ['3', '5']
G['5'] = ['4', '3']
G['4'] = ['3', '2']
G['3'] = ['1']
G['2'] = ['1']
G['1'] = []
printBuildOrder(G)
