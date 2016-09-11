def tripleSteps(n, steps, cache):

    if n < 0:
        return 0

    if n == 0:
         return 1

    if n in cache:
        return cache[n]

    currentSum = 0
    for step in steps:
        currentSum += tripleSteps(n-step, steps, cache)
        cache[n]    = currentSum

    return currentSum

def triple(n, steps):
    cache = dict()
    return tripleSteps(n, steps, cache)

n = 4
steps = [1,2,3]
print triple(n, steps)

