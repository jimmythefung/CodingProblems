def zeroMatrix(M):
    m = len(M)
    n = len(M[0])
    i = 0
    j = 0
    rowTable = set()
    colTable = set()
    for i in range(m):
        for j in range(n):
            if M[i][j] == 0:
                rowTable.add(i)
                colTable.add(j)

    for row in rowTable:
        clearRow(M, row)
    for col in colTable:
        clearCol(M, col)

def clearRow(M, row):
    n = len(M[0])
    for j in range(n):
        M[row][j] = 0

def clearCol(M, col):
    m = len(M)
    for i in range(m):
        M[i][col] = 0

def printM(M):
    for line in M:
        print line
    print ""
    
M = [[1,0,3],[4,5,6],[7,8,9]]
printM(M)

zeroMatrix(M)
printM(M)
