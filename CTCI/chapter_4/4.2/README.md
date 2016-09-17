# Minimal Tree:  
Given a sorted (increasing order) array with unique integer elements, write an algorithm to create a binary search tree with minimal height.  

# Idea  
Let A be the input array, then:  
A = L + A[m] + R  
  = A[0:m] + A[m] + A[m:]  
A[m] would be the root of the tree  

