def rotateCell(M,a,b,c,d):
    temp          = M[b[0]][b[1]] # b -> temp
    M[b[0]][b[1]] = M[a[0]][a[1]] # a -> b
    M[a[0]][a[1]] = M[c[0]][c[1]] # c -> a
    M[c[0]][c[1]] = M[d[0]][d[1]] # d -> c
    M[d[0]][d[1]] = temp          # temp -> d

def rotateMatrix(M):
    N = len(M[0])
    for shell in range(N/2):
        wall = N-shell-1
        i    = shell
        while i < wall:
            ar = shell
            ac = i
            a  = [ar, ac]

            br = i
            bc = wall
            b  = [br, bc]

            cr = N-1 - i # it's (N-1)-i. Not (wall)-i. Because i=shell at each new loop
            cc = shell
            c  = [cr, cc]

            dr = wall
            dc = N-1 - i
            d  = [dr, dc]
            if shell == 1:
                print a, b, c, d

            rotateCell(M,a,b,c,d)
            i = i + 1
            
    

def printMatrix(M):
    for line in M:
        print line
    print ""


# original matrix
M = [ ['01','02','03','04'], ['05','06','07','08'], ['09','10','11','12'], ['13','14','15','16']]
#M = [ [1,2], [3,4] ]
printMatrix(M)

# Rotate Matrix
rotateMatrix(M)
print printMatrix(M)
