def constructSubmatrix(matrix, rowsToDelete, columnsToDelete):
    m = len(matrix) # number of rows
    n = len(matrix[0]) # number of columsn

    rKeep = set( range(0,m) )
    cKeep = set( range(0,n) )

    for ind in rowsToDelete:
        rKeep.remove(ind)

    for ind in columnsToDelete:
        cKeep.remove(ind)

    # Initialize submatrix
    submatrix = [ [0 for col in range( len(cKeep) )] for row in range( len(rKeep) ) ]

    # Populate
    y = 0
    for r in sorted(rKeep):
        x = 0
        for c in sorted(cKeep):
            submatrix[y][x] = matrix[r][c]
            x += 1
        y+=1

    return submatrix

    
    
    
matrix = [ [1,0,0,2],
           [0,5,0,1],
           [0,0,3,5] ]

rDelete = [1]
cDelete = [0,2]

sm = constructSubmatrix(matrix, rDelete, cDelete)
print(sm)
