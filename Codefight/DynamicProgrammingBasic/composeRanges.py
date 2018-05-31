def composeRanges(nums):
    partitions = []
    partitionDisjoint(nums, partitions)
    
    result = []
    for p in partitions:
        if len(p)>1:
            result.append( str(p[0]) + "->" + str(p[-1])  )
        elif len(p)==1:
            result.append( str(p[0]) )
        else:
            pass
    return result


def partitionDisjoint(nums, partitions):
    start = 0
    if len(nums) > 1:
        i = 1
        while i < len(nums):
            if nums[i-1] != nums[i]-1:
                partitions.append(nums[start:i])
                start = i
            i+=1
    partitions.append(nums[start:])
    

nums = [-1, 0, 1, 2, 6, 7, 9]
print( composeRanges(nums) )
