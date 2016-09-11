# Rotate Matrix: Given an image represented by NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?  

# Idea   
Write a helper function called RotateCell that rotate 4 cells per call.  
Afterward, it's just iterating the Matrix from outter most shell to inner most shell, calling RotateCell on each cell.  

The iteration is only n/2 long. Because each time a shell is processed, the shell is removed, which is 2 rows or 2 columns in thickness.
