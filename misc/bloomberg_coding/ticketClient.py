class tickerClient(object):
    table = dict()

    def __init__(self):
        pass
    
    def peek(self, ticker):
        return self.table[ticker][-1]

    def insert(self, ticker, price):
        self.table.setdefault(ticker, []).append(price)

    def remove(self):
        pass

c = tickerClient()
c.insert('ibm', 34.4)
c.insert('ibm', 37)
print( c.table )
print( c.peek('ibm') )
c.insert('bnb', 12.3)
c.insert('bnb', 43)
print( c.table )
print( c.peek('bnb') )
