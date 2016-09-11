# Is Unique string  
Implement an algorithm to determine if a string has all unique characters. What if you cannot use a data structure?  

# Idea:  
1. Use data structure - a hashTable to keep count the frequncy of characters. If frequency greater than 1 we have none unique.  
2. If no data structure allowed, then we can sort the string and iterate to see s[i-1] == s[i]. Return false if so.  
