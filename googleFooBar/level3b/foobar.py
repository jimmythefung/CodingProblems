def answer(maze):
    M = [row[:] for row in maze]
    h = len(M)
    w = len(M[0])
    solutionSet = set()

    # explore solution with no wall removed
    mazeBFS(M, (0,0), (h-1, w-1), solutionSet)

    # explore other solutions with 1 wall removed
    for r in range(h):
        for c in range(w):
            if M[r][c]==1:
                M[r][c]=0 # remove one wall
                mazeBFS(M, (0,0), (h-1, w-1), solutionSet)
                M[r][c]=1 # undo wall removal
                
    return min(solutionSet)

# BFS alternatively from src and dst
def mazeBFS(M, src, dst, solutionSet):
    from collections import deque
    srcQ = deque()
    dstQ = deque()
    srcVisited=dict()
    dstVisited=dict()
    
    h = len(M)
    w = len(M[0])

    srcQ.append(src)
    dstQ.append(dst)
    srcSteps = 0
    dstSteps = 0
    
    turnFlag = 2
    while len(srcQ)!=0 and len(dstQ)!=0:

        # src turn to explore next BFS level
        if turnFlag%2 == 0:
            
            srcSteps += 1
            srcQ_size = len(srcQ)
            
            for i in range(srcQ_size):
                pos = srcQ.popleft()
                r = pos[0]
                c = pos[1]
                
                # out of bound
                if r < 0 or r > h-1 or c < 0 or c > w-1:
                    pass

                # hit a wall - not allowed
                elif M[r][c] == 1:
                    pass
                
                # already visited
                elif pos in srcVisited:
                    pass
                
                # non-optimal solution
                elif len(solutionSet)!= 0 and (srcSteps + dstSteps) >= min(solutionSet):
                    return # exit search, this maze is suboptimal
                
                # solution found
                elif pos==(dst):
                    result = srcSteps
                    print "a:", pos, ": pos=dst", result
                    solutionSet.add(result)
                    return      
                elif (pos in dstVisited):
                    
                    result = srcSteps + dstVisited[pos] - 1
                    print "b:", pos, ":pos in dstVsited", result
                    solutionSet.add(result)
                    return # no later solution will be more optimal
                    
                # normal case
                else:
                    srcVisited[pos] = srcSteps
            
                    # enque: right, left, up, down
                    srcQ.append((r,c+1))
                    srcQ.append((r,c-1))
                    srcQ.append((r-1,c))
                    srcQ.append((r+1,c))


        # dst turn to explore next BFS level
        else:
            dstSteps += 1
            dstQ_size = len(dstQ)
            
            for i in range(dstQ_size):
                pos = dstQ.popleft()
                r = pos[0]
                c = pos[1]
                
                # out of bound
                if r < 0 or r > h-1 or c < 0 or c > w-1:
                    # print "out of bound"
                    pass

                # hit a wall - not allowed
                elif M[r][c] == 1:
                    pass
                
                # already visited
                elif pos in dstVisited:
                    # print "already visited", pos
                    pass
                
                # non-optimal solution
                elif len(solutionSet)!= 0 and (srcSteps + dstSteps) >= min(solutionSet):
                    return # exit search, this maze is suboptimal
                
                # solution found
                elif pos==(src):
                    result = dstSteps
                    solutionSet.add(result)
                    return      
                elif (pos in srcVisited):
                    result = dstSteps + srcVisited[pos] - 1
                    solutionSet.add(result)
                    return # no later solution will be more optimal
                    
                # normal case
                else:
                    dstVisited[pos] = dstSteps
            
                    # enque: right, left, up, down
                    dstQ.append((r,c+1))
                    dstQ.append((r,c-1))
                    dstQ.append((r-1,c))
                    dstQ.append((r+1,c))

        turnFlag+=1

        


def printM(M):
    for row in M:
        print row
    print ""

maze = [[0, 1, 1, 0], [0, 0, 0, 1], [1, 1, 0, 0], [1, 1, 1, 0]]
maze2 = [ [0,0,0,0,0,0], [1,1,1,1,1,0], [0,0,0,0,0,0], [0,1,1,1,1,1], [0,1,1,1,1,1], [0,0,0,0,0,0]]
maze3 = [ [0,0,0,0,0,0], [0,0,0,0,0,0], [0,0,0,0,0,0], [0,0,0,0,0,0], [0,0,0,0,0,0], [0,0,0,0,0,0]]


maze4 = [ [0, 0], [1,0] ] # special case 2x2
maze5 = [ [0, 1], [1,0] ] # special case no solution with no wall removed
maze6 = [ [0,1,1], [1,1,1], [1,1,1],[1,1,0]]

M = maze6
printM(M)
print answer(M)

