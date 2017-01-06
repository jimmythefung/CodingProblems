class Solution(object):
    def twoSum(self, nums, target):
        from collections import deque
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        indTable = dict()
        i=0
        for e in nums:
            if e not in indTable:
                indTable[e] = deque()
                indTable[e].append(i)
            else:
                indTable[e].append(i)
            i += 1
        
        sortedArr = sorted(nums)
        
        a = 0
        b = len(sortedArr)-1
        
        while True:
            mySum = sortedArr[a] + sortedArr[b]
            if (mySum == target):
                return [indTable[sortedArr[a]].popleft(), indTable[sortedArr[b]].popleft()]
            elif mySum > target:
                b -= 1
            else:
                a += 1
            
            if a >= b:
                break
            
