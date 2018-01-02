class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        return removeVal(nums, val)
        
def removeVal(arr, val):
    size = len(arr)
    if size == 0:
        return size
    
    # Loop invariant initialization
    A = 0
    B = 0
    while B<size and arr[B]==val:
        B+=1
    if B == size:
        return 0
    arr[A] = arr[B]
    B+=1
        
    
    # Loop invariant:
    #   At start, partition bounded by index 0 up to including "A" consists of all desired elements
    #   Element at index B is uninspected
    #   Parittion bounded by index A up to but exclude B are the removed element
    while B < size:
        if arr[B]!=val:
            A+=1
            arr[A] = arr[B]
        B+=1

    # index A bounds the proper array. A+1 is hence the size.
    return A+1

    
arr = [1]
print removeVal(arr, 1)
print arr
