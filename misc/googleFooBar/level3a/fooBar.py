def answer(n):
    cache = dict()
    return rStep(n, 0, cache)

def rStep(n, prev, cache):
    
    # base case: we cached the solution
    if (n, prev) in cache:
        return cache[(n, prev)]
    
    # base case: no more steps, solution!
    if n==0:
        cache[(n, prev)] = 1
        return 1
    
    # base case: not enough steps
    if n <= prev:
        cache[(n, prev)] = 0
        return 0


    # normal case
    mySum = 0
    taken = prev + 1
    while taken <= n:

        if prev==0 and taken==n:
            break
        
        leftOver = n - taken

        nSolutions = rStep(leftOver, taken, cache)
        mySum += nSolutions


        taken += 1

        
    cache[(n,prev)] = mySum
    return mySum

print answer(3)
print answer(5)
print answer(10)
print answer(50)
print answer(100)
print answer(200)
