def isPermutation(s1, s2):
    d = dict()
    for c in s1:
        if c not in d:
            d[c]=1
        else:
            d[c]+=1

    for c in s2:
        if c in d:
            d[c]-=1
        else:
            return False

    for key,value in d.iteritems():
        if value!=0:
            return False
    return True

s1 = "abc"
s2 = "cbab"

print "Is "+s1+" permutation of "+s2+"?", isPermutation(s1,s2)
