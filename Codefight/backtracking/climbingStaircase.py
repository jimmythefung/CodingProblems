import sys
import os
sys.path.append(os.path.abspath("../"))
from binaryTree import *

def climbingStaircase(n, k):
    validStairHeights = dict()
    validStairHeights[0] = []
    rjump(n,k,validStairHeights)
    
    path = []
    result = []
    buildSolution(n, validStairHeights, path, result)
    return result

def rjump(n, k, validStairHeights):
    if n in validStairHeights:
        return True
    if n==0:
        return True
    if n<0:
        return False
    
    hasSolution = False
    for jumpSize in range(1, k+1):
        stairHeight = n-jumpSize
        if rjump(stairHeight, k, validStairHeights):
            validStairHeights.setdefault(n, []).append(stairHeight)
            hasSolution = True
    return hasSolution
        

def buildSolution(n, validStairHeights, path, result):
    if n == 0:
        result.append( path[:] )
        return

    for stairHeight in validStairHeights[n]:
        jumpSize = n-stairHeight
        path.append(jumpSize)
        buildSolution(stairHeight, validStairHeights, path, result)
        path.pop()
    

print( climbingStaircase(4, 2) )
