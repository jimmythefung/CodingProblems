# Problem: https://leetcode.com/problems/search-insert-position/
# Given a sorted array of distinct integers and a target value,
# return the index if the target is found. If not, return the index where it would be if it were inserted in order.

class Solution:
	# O(n)
    def searchInsert(self, nums: List[int], target: int) -> int:
        for x, i in enumerate(nums):
        	if x>=target:
        		return i
        	return i+1

    # O(log(n))
    def searchInsert(self, nums: List[int], target: int) -> int:
    	a = 0
    	b = len(nums) - 1

    	# Easy check outside bound
    	if target > nums[b]:
    		return b+1
    	if target < nums[a]:
    		return a

    	while True:
    		# Evaluate midpoint
    		m = (b-a)//2 + a
    		mval = nums[m]
    		if target==mval:# [a, m, b]
    			return m
    		# Adjust boundary
    		if target>mval: # [a, m, b] -> [], [a=b]
    			a = m+1
    			if a>b:
    				return a
    		if target<mval: # [a, m, b] -> [a=b], []
    			b = m-1
    			if a>b:
    				return b+1
