def sumOfTwo(a, b, v):
    aCache = set(a)
    bCache = set(b)
    
    for a in aCache:
        btest = v - a
        if btest in bCache:
            return True
    
    for b in bCache:
        atest = v - b
        if atest in aCache:
            return True
    
    return False
