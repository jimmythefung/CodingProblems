# Route Between Nodes:  
Given a directed graph, design an algorithm to find out whether there is a route between two nodes.  


# Idea  
Use BFS  
BFS simultaneously at BOTH the src and dst nodes  
Iterate BFS depth through while loop. Use queue to keep track of all nodes at current BFS Depth.  
For each visited node, they must be marked.  
Therefore, we found the answer if we arrive at a visited node.  
Otherwise, there's no path.

