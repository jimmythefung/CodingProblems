import sys

def sum4(S, t):
    S.sort()
    solS = set()
    for i in range(0, len(S)-3):
        for j in range(i+1, len(S)-2): # O(n2)
            k = j+1
            l = len(S)-1
            while k < l:               #O(n)
                #print i, j, k, l
                curr_sum = S[i] + S[j] + S[k] + S[l]
                if curr_sum == t:
                    solS.add((S[i], S[j], S[k], S[l]))
                if curr_sum < t:
                    k+=1
                else:
                    l-=1
    return list(solS)

# [[-3,-2,2,3],[-3,-1,1,3],[-3,0,0,3],[-3,0,1,2],[-2,-1,0,3],[-2,-1,1,2]**,[-2,0,0,2],[-1,0,0,1]]
S = [-3,-2,-1,0,0,1,2,3]
target = 0
print sum4(S, target)
