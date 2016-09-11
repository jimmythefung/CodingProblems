# One Away:  
There are 3 types of edits that can be performed on strings:  
- insert a character  
- remove a character, or  
- replace a character  
  
Given two strings, write a function to check if they are one edit away.  
  
Example:  
pale, ple -> true  
pales, pale -> true  
pale, bale -> true  
pale, bake -> false  
  

# Idea  
delta =  1 // insert  
delta = -1 // remove  
delta =  0 // replace  
  
build charTableS1 and charTableS2, take their difference, call it delta.  
  

