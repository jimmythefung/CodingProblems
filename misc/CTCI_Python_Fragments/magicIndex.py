def magicIndex(A, start, end):
    if start >= end:
        if start==end and A[start]==start:
            return start
        else:
            return False

    m = (end-start)/2 + start

    if A[m] == m:
        return m
    elif A[m] > m:
        return magicIndex(A, L, m)
    else: # A[m] < m
        return magicIndex(A, m+1, end)



A = [9, 4, 2, 6, 3, 1]
print magicIndex(A, 0, len(A)-1)

    
B = [9, 4, 0, 6, 3, 1]
print magicIndex(B, 0, len(B)-1)


C = [0,1,2,3,4,5]
print magicIndex(C, 0, len(C)-1)
