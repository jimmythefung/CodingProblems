# Triple Step  
A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 stepsat a time. Implement a method to count how many possible ways the child can run up the stairs.  

# Idea  
Dynamic Programming + Recursion.  

Recursion:  
Start from state = n. For each state, recurse into n-1, n-2, and n-3 state in a DFS manner.  
  
Dynamic Programming:  
When recursed into state n=0 or returning to previous recursion frame, cache the number of solutions returned by the recursion subroutine above.  




