def paintFill(M, pos, oldColor, newColor):
    m = len(M)
    n = len(M[0])

    row = pos[0]
    col = pos[1]

    # Check out of bound
    if row < 0 or row > m-1 or col < 0 or col > n-1:
        return None

    # Base case: color not original
    if M[row][col] != oldColor:
        return None
    else:
        M[row][col] = newColor

    # DFS
    paintFill(M, (row-1, col)  , oldColor, newColor) # Up
    paintFill(M, (row  , col+1), oldColor, newColor) # Right
    paintFill(M, (row+1, col)  , oldColor, newColor) # Down
    paintFill(M, (row  , col-1), oldColor, newColor) # Left

def printM(M):
    for row in M:
        for e in row:
            print e,
        print ""





M = [[1, 2, 3, 4], [1, 2, 2, 4], [4, 2, 2, 1], [2, 2, 1, 2]]
print "Input color matrix (color represented by integers"
printM(M)



pos = (0,1)
oldColor = M[pos[0]][pos[1]]
newColor = 0
print "PaintFill", pos, "with old color:", oldColor, "and new color:", newColor
paintFill(M, pos, oldColor, newColor)
printM(M)
