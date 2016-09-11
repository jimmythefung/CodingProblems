# Remove Dups:  
Write code to remove duplicates from an unsorted linked list.

# Idea  
1. Create a set, then iterate linked list. Insert the data into set if not already in set. Otherwise, remove the current node by re-arranging the "next" and "prev" pointer.  
Careful! If singly linked list is used, use two node pointers (one ahead of each other) so removing the current node can be handled with the help of a pointer pointing to previous node.  

  

