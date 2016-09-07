def intToBinary(x):
    A = []

    while x!=0:
        exp = getExp(x)
        A.append(exp)
        x = x-pow(2,exp)

    B = ["0"]*A[0]
    i = 0
    while i < len(A):
        B[ len(B)-1 - A[i] ] = str(1)
        i += 1

    return "".join(B)

def getExp(x):
    exp = 0
    b = 1
    while True:
        b = b << 1
        exp += 1
        if b == x:
            return exp
        elif b > x:
            return exp-1
        else:
            pass
x = 31
print "Input x =", x
print "Output binary(x) =", intToBinary(x)
