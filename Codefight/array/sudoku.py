def sudoku2(grid):
    n = 9
    m = 3
    rowSets = []
    colSets = []
    regionSets = []
    for i in range(m):
        regionSets.append( [] )
        for j in range(m):
            rowSets.append( set() )
            colSets.append( set() )
            regionSets[i].append( set() )
    for r in range(n):
        for c in range(n):
            x = grid[r][c]
            if x.isdigit():
                # Check row set
                if x in rowSets[r]:
                    return False
                else:
                    rowSets[r].add( x )
                # Check col set
                if x in colSets[c]:
                    return False
                else:
                    colSets[c].add( x )
                # Check region set. Map r, c to quotient space
                qr = r//3
                qc = c//3
                if x in regionSets[qr][qc]:
                    return False
                else:
                    regionSets[qr][qc].add( x )
    return True


##grid = [['.', '.', '.', '1', '4', '.', '.', '2', '.'],
##        ['.', '.', '6', '.', '.', '.', '.', '.', '.'],
##        ['.', '.', '.', '.', '.', '.', '.', '.', '.'],
##        ['.', '.', '1', '.', '.', '.', '.', '.', '.'],
##        ['.', '6', '7', '.', '.', '.', '.', '.', '9'],
##        ['.', '.', '.', '.', '.', '.', '8', '1', '.'],
##        ['.', '3', '.', '.', '.', '.', '.', '.', '6'],
##        ['.', '.', '.', '.', '.', '7', '.', '.', '.'],
##        ['.', '.', '.', '5', '.', '.', '.', '7', '.']]

##grid = [['.', '.', '.', '.', '2', '.', '.', '9', '.'],
##        ['.', '.', '.', '.', '6', '.', '.', '.', '.'],
##        ['7', '1', '.', '.', '7', '5', '.', '.', '.'],
##        ['.', '7', '.', '.', '.', '.', '.', '.', '.'],
##        ['.', '.', '.', '.', '8', '3', '.', '.', '.'],
##        ['.', '.', '8', '.', '.', '7', '.', '6', '.'],
##        ['.', '.', '.', '.', '.', '2', '.', '.', '.'],
##        ['.', '1', '.', '2', '.', '.', '.', '.', '.'],
##        ['.', '2', '.', '.', '3', '.', '.', '.', '.']]

grid = [ [".",".",".",".",".",".","5",".","."], 
         [".",".",".",".",".",".",".",".","."], 
         [".",".",".",".",".",".",".",".","."], 
         ["9","3",".",".","2",".","4",".","."], 
         [".",".","7",".",".",".","3",".","."], 
         [".",".",".",".",".",".",".",".","."], 
         [".",".",".","3","4",".",".",".","."], 
         [".",".",".",".",".","3",".",".","."], 
         [".",".",".",".",".","5","2",".","."]]

print( sudoku2(grid) )
