# Palindrome Permutation  
Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or a phrase that is the same forward and backward. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.  
Example:  
Input: Tact Coa  
Output: True (permutations: "taco cat", "atco cta", etc.)  

# Idea  
For any permutation, we employ hash table to count for "even" number of characters plus at most 1 single character.  


