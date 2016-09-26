# List of Depths:  
Given a binary tree, design an algorithm which create a linked list of all the nodes at each depth (if you have a tree with depth D, you will have D linked lists).  

# Idea  
 Use deque to BFS the tree given a root node.  
 For each iteration of BFS traversal, records the length of the deque (this is the number of nodes in the current level). Then in an inner loop, iteratively insert each node into a list and append their childs into the deque, if any.  
 At the end of each inner loop, append the list back into the result vector.  


