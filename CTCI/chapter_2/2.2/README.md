# Return Kth to Last:  
Implement an algorithm to find the kth to last elements of a single linked list.  

# Idea  
Use 2 pointers seperated by a distance of k, call them pointer "a", "b" where "b" is ahead by k.  
Clearly, when "b" is at the end of linked list, our "a" points to our answer.  

  

