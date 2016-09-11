def permutation(s_in):
    if len(s_in) <= 1:
        return [s_in]
    
    subset = permutation(s_in[1:]) # recurse into string s_in of n-1 size from back
    output = []
    for s in subset:
        for i in range( len(s)+1 ):
            output.append( s[:i] + s_in[0] + s[i:] )
    return output

def permWithDups(s_in):
    if len(s_in) <= 1:
        output = set()
        output.add(s_in)
        return output

    output = set()
    subset = permWithDups(s_in[1:])

    for s in subset:
        for i in range(len(s)+1):
            newS = s[:i] + s_in[0] + s[i:]
            if newS not in output:
                output.add(newS)
    return output

print "permutation:"
s_in = "abcc"
for s in permutation(s_in):
    print s

print ""
print "permWithDups:"
s_in = "abcc"
mySet = permWithDups(s_in)
for s in mySet:
    print s
