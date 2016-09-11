def changeForN(n, change, freqCache, pathCache, count):

    if n < 0:
        return count[0]

    if n == 0:
        pathString = ""
        for c in change:    # Huffman encode the change-path to be recorded for unqiueness
            pathString += "$"+str(c)+":"+str(freqCache[c])+" "
            
        if pathString not in pathCache:
            count[0]+=1
            pathCache.add(pathString)
        return count[0]

    for c in change:
        freqCache[c] += 1   # insert change prior to entering recursion
        changeForN(n-c, change, freqCache, pathCache, count)
        freqCache[c] -= 1   # undo inserted change after exiting recursion

    return count[0]

def changeDriver(n, change):
    pathCache = set()
    count = [0]
    freqCache = dict() # initialize the hash table for occurances of change to all 0s 
    for c in change:
        freqCache[c] = 0
    changeForN(n, change, freqCache, pathCache, count)

    print "n =", n
    print count[0], "solutions found:"
    i = 1
    for path in pathCache:
        print "Solution",i,":", path
        i += 1

    return count[0]

n = 20
change = [1, 5, 10, 20, 50]
changeDriver(n, change)
