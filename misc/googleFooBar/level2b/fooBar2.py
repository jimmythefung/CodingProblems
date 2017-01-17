def answer(l, t):
    # cacheSum maps the current sum as the key to the index where this sum is attained
    cacheSum = dict()
    mySum = 0
    
    i = 0
    while i < len(l):
        mySum += l[i]
        if mySum not in cacheSum:
            cacheSum[mySum] = i

        offset = mySum-t
        if offset == 0:
            return [0, i]
        if offset in cacheSum:
            startInd = cacheSum[offset] + 1
            endInd = i
            return [startInd, endInd]

        i += 1

    return [-1, -1]


# tests
l = [4, 3, 5, 7, 8]
t = 12
print answer(l, t)

l1 = [4, 3, 10, 2, 8]
t1 = 12
print answer(l1, t1)

l2 = [1, 2, 3, 4]
t2 = 15
print answer(l2, t2)

l3 = [1, 2, 3, 4, 5]
t3 = 15
print answer(l3, t3)
