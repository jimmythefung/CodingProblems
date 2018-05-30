def zigzag(a):
    # Base case
    if len(a) == 1:
        return 1
    if len(a) < 1:
        return 0
    
    maxSeen = 0
    last = 'flat'
    l=0
    i = 1
    while i < len(a):
        
        r = a[i] - a[i-1]
        if r > 0:
            f = 'zig'
        elif r < 0 :
            f = 'zag'
        else:
            f = 'flat'

        if f!=last:
            l+=1
        else:
            l=0
        if f=='flat':
            l=0
            
        
        
        if l > maxSeen:
            maxSeen = l
        
        last = f
        i+=1
        
    return maxSeen+1

a = [2, 1, 4, 4, 1, 4, 4, 1, 2, 0, 1, 0, 0, 3, 1, 3, 4, 1, 3, 4]

print( zigzag(a) )
