def answer(src, dest):
    # your code here
    # initialize mapping frmo "gameboard cell number" to "row-column representation"
    board = dict()
    i = 0
    for r in range(8):
        for c in range(8):
            board[i] = (r,c)
            i = i + 1

    source      = board[src]
    destination = board[dest]
    
    solutionSet = set()
    pastPos = set()
    stepCount = 0

    rDFS(source, destination, stepCount, pastPos, solutionSet)
    return min(solutionSet)

def rDFS(src, dst, stepCount, pastPos, solutionSet):# pos = (row, column)
    
    r = src[0]
    c = src[1]

    # out of bound
    if r > 7 or c > 7 or r < 0 or c < 0:
        return

    # can't be optimal solution
    if len(solutionSet)!=0 and stepCount >= min(solutionSet):
        return

    # arrived at dst
    if src == dst:
        print stepCount
        solutionSet.add(stepCount)
        return


    # been here before
    if src in pastPos:
        return


    # Make the next 8 moves in DFS manner
    pastPos.add(src)
    
    # Right move, c+2
    rDFS((r-1,c+2), dst, stepCount+1, pastPos, solutionSet) # up
    rDFS((r+1,c+2), dst, stepCount+1, pastPos, solutionSet) # down

    # Left move, c-2
    rDFS((r-1,c-2), dst, stepCount+1, pastPos, solutionSet) # up
    rDFS((r+1,c-2), dst, stepCount+1, pastPos, solutionSet) # down
        
    # Up move, r-2
    rDFS((r-2,c+1), dst, stepCount+1, pastPos, solutionSet) # right
    rDFS((r-2,c-1), dst, stepCount+1, pastPos, solutionSet) # left

    # Down move, r+2
    rDFS((r+2,c+1), dst, stepCount+1, pastPos, solutionSet) # right
    rDFS((r+2,c-1), dst, stepCount+1, pastPos, solutionSet) # left

    # undo current visited cell when exiting recursion
    pastPos.remove(src)
    return 
