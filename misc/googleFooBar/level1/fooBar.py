def answer(plaintext):
    d = {
        'a':'1',
        'b':'12',
        'c':'14',
        'd':'145',
        'e':'15',
        'f':'124',
        'g':'1245',
        'h':'125',
        'i':'24',
        'j':'245',
        'k':'13',
        'l':'123',
        'm':'134',
        'n':'1345',
        'o':'135',
        'p':'1234',
        'q':'12345',
        'r':'1235',
        's':'234',
        't':'2345',
        'u':'136',
        'v':'1236',
        'w':'2456',
        'x':'1346',
        'y':'13456',
        'z':'1356'
        }
    keyM = {
        '1':(0,0),
        '2':(0,1),
        '3':(0,2),
        '4':(1,0),
        '5':(1,1),
        '6':(1,2)
        }

    s = ''
    for c in list(plaintext):
        # case: c is white space
        if c == ' ':
            s += '000000'
        # case: c is uppercase
        elif c.isupper():
            s += '000001'
            s += readChar(c.lower(), d, keyM)
        # case: c is normal lowercase char
        else:
            s += readChar(c, d, keyM)

    return s

def readChar(c, d, keyM):
    state = [[0, 0, 0], [0, 0, 0]]
    l = list(d[c])
    for k in l:
        r = keyM[k][0]
        c = keyM[k][1]
        state[r][c] = 1

    s = ''
    for row in state:
        for binary in row:
            s = s + str(binary)
    return s

print "look", answer('look')
print "code", answer('code')
print "Braille", answer('Braille')

