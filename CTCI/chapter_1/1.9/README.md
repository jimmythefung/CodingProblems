# String Rotation:  
Assume you have a method isSubstring() which checks if one word is a substring of another. Given two strings s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring().  
Example:  
"waterbottle" is a rotation of "erbottlewat"  

# Idea  
Concatenate s1 with s1, call it s:  
s = s1 + s1  

return isSubstring(s, s2)
  

