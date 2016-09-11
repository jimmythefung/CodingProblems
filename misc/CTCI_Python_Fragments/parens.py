def parens(n):

    output = set()
    if n==1:
        output.add("()")
        return output

    subset = parens(n-1)
    for p in subset:
        output.add("()"+p)
        output.add(p+"()")
        output.add("(" + p + ")")

    return output

def parenPrint(n):
    print "n =", n
    mySet = parens(n)
    for p in mySet:
        print p
    print ""




n = 4
for i in range(n):
    parenPrint(i+1)
