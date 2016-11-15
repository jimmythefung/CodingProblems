# Magic Index:  
A magic index in an array [0, ..., N-1] is defined to be an index such that A[i] = i.  
Given a sorted array of distinct integers, write a method to find a magic index, if it exits, in an array A.  

FOLLOW UP:  
What if the values are not distinct?

# Idea  
Observations:  
1. Case 1 - if the middle index, m, is such that the value A[m] > m, then the right half of array A would not contain middle index. But possible in the left.  
2. Case 2 - A[m] < m. Then right half may contain m. But not left half. So we must search right half. 
3. Case 3 - A[m] == m. Done.  
  

