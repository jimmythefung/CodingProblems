# Zero Matrix:  
Write an algorithm such that if an element in MxN matrix is 0, its entire row and column are set to 0.  


# Idea  
1. Write two helper functions whose sole purpose is to set all row and columns to zero, given a cell.  
2. Create two tables, one for row and one for column, to keep track which one has an element 0.  
3. Iterate the two tables, calling helper functions on the elements.  

