def twoSum(nums, target):
    B = dict() # t = (delta) + B, this maps: delta=(t-B) -> index(B); so we check if at a later time that delta is found

    i = 0
    for delta in nums:
    	if delta in B:
    		return [B[delta], i]
    	
    	B[ target-delta ] = i # newDelta = target-delta
    	i += 1
    return [0, 0]