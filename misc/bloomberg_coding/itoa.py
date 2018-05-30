# e.g. n=341 -> '341'
from collections import deque
def itoa(n):
    q = deque()
    while n!=0:
        # Extract right most digit, offset by ascii '0', converts to string 
        q.appendleft( chr( ord('0')+n%10 ) )
        
        # Right shift base 10
        n = n//10

    return ''.join(q)

# test 1
n = 341
print(itoa(n))
        
    
