def containsCloseNums(nums, k):
    d = dict()
    for i,x in enumerate(nums):
        if x not in d:
            d[x] = i
        else:
            if abs(i - d[x]) <= k:
                return True
            else:
                d[x] = i
    return False
