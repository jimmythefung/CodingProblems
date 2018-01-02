class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return removeDup(nums)

def removeDup(nums):
    size = len(nums)
    if size <= 1:
        return size
    a=0
    b=0
    # Loop invariant: a at last unique value, b at uninspected value
    while b < size:
        if nums[a]!=nums[b]:
            a+=1
            nums[a] = nums[b]
        b += 1
    return a+1

arr = [1,2]
print removeDup(arr)
print arr
