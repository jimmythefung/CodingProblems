# URLify:  
Write a method to replace all spaces in string with "%20".  
Input : s = "Mr John Smith    "  // n=13, s.size()=17; 4 spaces padded in back  
Output: s = "Mr%20John%20Smith"  
URLify(s, n)  

# Idea  
Use two index: a and b.
"a" keeps track of last elements of the original string.  
"b" keeps track of the position of the next unused space start at the end of array.  
Iteratively copy s[a] to s[b].  
- if s[a] is a space, s[b] fills in "%20"  
- decrement "a" and "b" accordingly.  

