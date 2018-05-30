# Simple class
class tickerClient(object):
    table = dict()
    
    def __init__(self):
        pass
    
    def peek(self, ticker):
        return self.table[ticker][-1]

    def insert(self, ticker, price):
        self.table.setdefault(ticker, []).append(price)
# Test tickerClient
c = tickerClient()
c.insert('ibm', 34.4)
c.insert('ibm', 37)
print( c.table )
print( c.peek('ibm') )




def atoi(a):
    tot = 0
    for d in a:
        x = ord(d)-ord('0')
        tot = tot*10 + x
    return tot
# Test atoi
a = '341'
print(atoi(a))




def itoa(n):
    from collections import deque
    q = deque()
    while n!=0:
        # Extract right most digit, offset by ascii '0', converts to string 
        q.appendleft( chr( ord('0')+n%10 ) )
        
        # Right shift base 10
        n = n//10
    return ''.join(q)
# Test itoa
n = 341
print(itoa(n))
