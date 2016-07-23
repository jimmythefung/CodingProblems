# Longest Palindrome  
https://www.careercup.com/question?id=5761604919492608   
  
# Problem detail  
Find the index when slow and fast pointer meet in terms of n (length of list before cycle) and p ( length of loop in linked list).  
Let the meeting index is q then we should be able to find value of q when we pass n& p , there shouldn't be any extra variable.  
    
# Solution idea:  
The question as stated has no unique solution, in the sense of not relying on extra variable. Clearly the answer, q, will be different depending on how much is p2 moving faster than p1.  
  
Here's the mathematical formula:  
Let's say p2 is moving faster than p1 by a factor of k.  
  
By the time p1 enters the loop (equivalently, traveled a distance n), p2 would have traveled a distance of kn.  
From here we can say the gap between p2 & p1 is G = (kn-n)%P.  
  
Then every subsequent step, s, the gap is increased by an amount (ks-s) = (k-1)s.  
The gap keeps increasing until p2 is exactly P ahead of p1. At this point, we have  
(k-1)s+G % P =0.  
  
And at this point, the location of p1 meeting p2, which we called "q" can be observed to be:  
q = s % P  
  
So we have 3 equations  
1. G = (kn-n)%P  
2. (k-1)s+G % P = 0  
3. q = s % P  
  
1. implies that there is a constant "x" such that Px+G = (kn-n)  
2. implies that there is a constant "y" such that Py = (k-1)s+G  
3. implies that there is a constant "z" such that Pz + q = s  
  
By manipulating the algebra of the 3 implications, you can obtain the following important result:  
  
q = P [(x+y)/(k-1) - z] - n  
  
which is the desired q as a function of P and n.  
  
Testing - Assume p2 is twice as faster as p1, so k=2, and we choose the constants x=y=z=1 (this means the p2 catches p1 without running more than 1 loop).  
The result simplifies to:  
  
q = P - n  
  
If the non-cycle part has length 3 and the cycle part has length 4, then  
  
q = 4 - 3 = 1.  
  
Which you can verify by drawing a picture.  
