# Fair Dice Problem  
https://www.careercup.com/page?pid=bloomberg-lp-interview-questions&n=2  

## Problem Statement  
Given n > 0 fair dice with m > 0 "sides", write an function that returns a histogram of the frequency of the result of dice rolls.  
For example, for two dice (n=2), each with three sides (m=3), the results are:  
  
(1, 1) -> 2  
(1, 2) -> 3  
(1, 3) -> 4  
(2, 1) -> 3  
(2, 2) -> 4  
(2, 3) -> 5  
(3, 1) -> 4  
(3, 2) -> 5  
(3, 3) -> 6  
  
And the function should return:  
  
2: 1  
3: 2  
4: 3  
5: 2  
6: 1 
  
## Solution idea  
This is a combination-like, n-choose-k allow re-use of chosen element, approach (as opposed to permutation-like explained below).  

Given "abcd" and k=2  
We form combination by first initializing all choices into their own set:  
k1 = { {a} {b} {c} {d} }  
We call the above k0 set, and we store the content of k1 in a double-ended queue data structure.  

We will need 3 nested loops.  
The first iterate the length of combination (so up to k)  
The second iterate the items in current queue (length of elements gets bigger by 1 each iteration, but size of queue grow as n!)  
The third iterate the given input n (i.e. a, b, c, d)  
  
Then for each iteration, i=1 up to k (note i=1 because initilization represented i=0)  
We pop a element from the above k-ith queue (i.e. {a}), then for each element, we create n copies (in this case n=4 because of a,b,c,d to choose from).  
And we append each possible new combination to them:  
Loop (j=1):  
{a}a  
{a}b  
{a}c  
{a}d  
Loop (j=2): 
{b}a  
{b}b  
{b}c  
.  
.  
.  
Loop (j=n): 
{d}a  
{d}b  
{d}c  
{d}d    
Then we form k2:  
k2 = { {aa}, {ab},..., {ba},..., {ca},..., {da},..{dd} } 
