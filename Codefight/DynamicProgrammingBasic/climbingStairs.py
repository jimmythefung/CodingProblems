def climbingStairs(n):
    cache = dict()
    return climb(n, cache)

def climb(n, cache):
    if n in cache:
        return cache[n]
    if n==0:
        cache[n] = 1
        return 1
    if n<0:
        return 0
    cache[n] = climb(n-2, cache) + climb(n-1, cache)
    return cache[n]
