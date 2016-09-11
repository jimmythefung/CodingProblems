def robot(M, pos, path, count):

    rSize = len(M)
    cSize = len(M[0])

    r = pos[0]
    c = pos[1]

    # out of bound
    if (r >= rSize) or (c >= cSize):
        return 0

    # obstacle cell
    if (M[r][c] == 0):
        return 0

    # exit cell
    if (M[r][c] == -1):
        count[0] += 1
        path.append( (r,c) )
        print path
        path.pop()
        return 1

    path.append( (r,c) )

    D = robot(M, (r+1, c), path, count)
    R = robot(M, (r, c+1), path, count)

    path.pop()

    return 1

def printM(M):
    for row in M:
        for item in row:
            print item,
        print ""


M = [ [1,1,1,1], [1,1,1,1], [1,1,1,1], [1,1,1,-1] ]
printM(M)

startPos = (0,0)
path = []
count = [0]
robot(M, startPos, path, count)
print "Number of paths:", count[0]
