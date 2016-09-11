from copy import copy, deepcopy
from collections import deque


def eightQueens(M):
    choices = deque()
    for i in range(len(M)):
        choices.append(i)

    solution = []
    solutionSet = []
    rSelect(M, choices, 0, solution, solutionSet)
    return len(solutionSet)

def rSelect(M_original, choices, r, solution, solutionSet):
    
    if len(solution) == 8:
        solutionSet.append(deepcopy(solution))
        return None

    for i in range(len(choices)):
        M = deepcopy(M_original)
        c = choices.popleft()
        isSet = setQueen(M, (r,c))
        if isSet == True:
            solution.append((r,c))
            rSelect(M, choices, r+1, solution, solutionSet)
            solution.pop()
        choices.append(c)
        

def setQueen(M, pos):
    if M[pos[0]][pos[1]] == 0:
        return False
    
    setRowZero(M, pos)
    setColZero(M, pos)
    setDiagZero(M, pos)
    M[pos[0]][pos[1]] = 1
    return True

def setRowZero(M, pos):
    for c in range(len(M[0])):
        M[pos[0]][c] = 0

def setColZero(M, pos):
    for r in range(len(M)):
        M[r][pos[1]] = 0

def setDiagZero(M, pos):
    rSize = len(M)
    cSize = len(M[0])

    # towards bottom right (r increasing)
    r = pos[0]
    c = pos[1]
    while r < rSize and c < cSize: 
        M[r][c] = 0
        r+=1
        c+=1
        
    # towards bottom left (r increasing)
    r = pos[0]
    c = pos[1]
    while r < rSize and c > -1: 
        M[r][c] = 0
        r+=1
        c-=1  

    # towards top right (r decreasing)
    r = pos[0]
    c = pos[1]
    while r > -1 and c < cSize:
        M[r][c] = 0
        r-=1
        c+=1     

    # towards top left (r decreasing)
    r = pos[0]
    c = pos[1]
    while r > -1 and c > -1:
        M[r][c] = 0
        r-=1
        c-=1
        
def printM(M):
    for row in M:
        for e in row:
            print e,
        print ""

M = [[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1]]
print "Input chess board (1 = valid for Queen placement)"
printM(M)

print "Number of solutions:",

print eightQueens(M)
