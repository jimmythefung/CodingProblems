# String Compression  
Implement a method to perform basic string compression using the counts of repeated characters.  
For example, the string "aabccccaaa" would become a2b1c5a3. If the compressed string would not become smaller than the original string, return the original string.  

# Idea  
Simply iterate through each character while keeping track of count, if it changes write it out to output string.  

