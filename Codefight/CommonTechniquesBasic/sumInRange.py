def sumInRange(nums, queries):
    cache = [0]*len(nums)
    tot = 0
    for ind, val in enumerate(nums):
        tot += val
        cache[ind] = tot
    
    
    tot = 0
    for q in queries:
        a, b = q[0], q[1]
        tot += (cache[b] - cache[a] + nums[a])
        
    return tot % (1000000007)

