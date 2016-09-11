def rMul(x,y):

    n,r = floorLog(y) # y=k+r where k=2^n

    xk = x << n # xy = x(k+r) = x(2^n) + xr

    if r == 0:
        return xk
    else:
        return xk + rMul(x,r)

def floorLog(y): # return the number of bit shift n, and remainder r
    if y == 0:
        return 0, 0
    tmp = y
    n = 0
    k = 1
    while tmp != 1:
        tmp = tmp >> 1
        k   = k << 1
        n   = n + 1
    r = y-k
    return n, r

for i in range(10):
    print rMul(3,i)

print rMul(3,31)
