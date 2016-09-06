# Print non overlapping pairs  
https://www.careercup.com/question?id=5689327699886080  
  
## Take an array and print non over lapping in order pairs. example:  
  
  
Input: [1,2,3,4]  
  
Output below is in order combination  
  
(1234)  
(1)(234)  
(1)(23)(4)  
(1)(2)(34)  
(12)(34)  
(12)(3)(4)  
(123)(4)  
(1)(2)(3)(4)  

# Solution Idea  
We incrasingly expand the parenthesis starting on the left, splitting the input as L+R:  
(L)(R)  
(1)(234)  // L=(1), R=(234) and so on  
(12)(34)  
(123)(4)  
(1234)  
  
We iterate through all case (expand parenthesis using loop).  
For each case, we recursively solve R. And cache result with Dynamic Programming.  
  
Observe 
R=(234)  
yields subproblem (2)(34):  
R'=(34)  
yields subproblem (3)(4):  
R''=(4)  
and terminates to base case.  
  
In other words, when we are at the first iteration where we work with  
Loop 1:  
(1)(234), we take R=(234) and recursively slove all permutations of R, then combine with L=(1) for first set of solution.  
Loop 2:  
(12)(34), we take R=(34) and recursively solve all permutations of R, then combine with L=(12) for second set of solution.  
And repeat loop until L=(1234), R=().  

