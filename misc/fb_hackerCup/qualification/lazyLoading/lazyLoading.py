def getTrips(arr):
    minWeight = 50
    arr = sorted(arr)
    a = -1 # the first lightest box might not be needed
    b = len(arr)-1
    tripsCount = 0

    weight = arr[b]
    h = 1
    while a < b:
        
        if h*weight >= minWeight:
            tripsCount += 1
            b -= 1
            h = 1
            weight = arr[b]
            if a==b:
                # this happen if before "b-=1", b is adjacent to a.
                break
        else:
            n = minWeight / weight
            r = minWeight % weight

            if r==0:
                a += n-1 # -1 to not double count the top weight
                h += n-1
            else:
                a += n
                h += n

    return tripsCount

def printCase(caseID, output):
    print "Case #"+str(caseID)+": "+str(output)

def readFromStdin():
    T = int(raw_input())
    for t in range(T):
        N = int(raw_input())
        arr = []
        for n in range(N):
            arr.append(int( raw_input() ))
        printCase(t+1, getTrips(arr))


if __name__ == "__main__":
    readFromStdin()
