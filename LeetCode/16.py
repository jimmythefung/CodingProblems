class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        return threeSumClosest2(nums, target)

import sys
def threeSumClosest2(nums, target):
    m = sys.maxint
    abc = 0
    for i in range(len(nums)):
        c = nums[i]
        arr = nums[:i] + nums[i+1:]
        delta, threeSum = twoSumMin(arr, c, target)
        if delta < m:
            m = delta
            abc = threeSum
    return abc

def twoSumMin(arr, c, t):
    m = sys.maxint
    abc = 0
    for i in range(len(arr)):
        j= i+1
        while j < len(arr):
            delta = abs(t-(arr[i]+arr[j]+c))
            if delta < m:
                m = delta
                abc = (arr[i]+arr[j]+c)
            j+=1
    return m, abc

#S = [-1, 0, 1, 2, -1, -4]
S = [-1, 2, 1, -4]
t = 1
print threeSum(S, t)
            
