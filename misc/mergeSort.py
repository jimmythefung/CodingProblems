def MS(A, start, end):
    if start >= end:
        return
    
    m = (end - start)/2 + start
    MS(A, start, m)
    MS(A, m+1, end)
    merge(A, start, m, end)

def merge(A, start, m, end):
    L = A[start:m+1]
    R = A[m+1:end+1]

    l = 0
    r = 0

    while l < len(L) and r < len(R):
        if L[l] < R[r]:
            A[start] = L[l]
            l += 1
        else:
            A[start] = R[r]
            r += 1
        start += 1

    if l < len(L):
        while l < len(L):
            A[start] = L[l]
            l += 1
            start += 1
    else:
        while r < len(R):
            A[start] = R[r]
            r += 1
            start += 1

A = [2, 6, 3, 3, 0, 9]
print A
MS(A, 0, len(A)-1)
print A
