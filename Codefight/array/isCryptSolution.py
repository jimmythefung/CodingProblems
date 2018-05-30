def isCryptSolution(crypt, solution):
    # Covert solution to dictionary for O(1) look up
    cipher = {}
    for pair in solution:
        cipher[pair[0]] = pair[1]

    # Convert each word to number-strings
    a = cryptToA( crypt[0], cipher )
    b = cryptToA( crypt[1], cipher )
    c = cryptToA( crypt[2], cipher )

    # Check leading zeroes
    if (a[0]=='0' and len(a)>1):
        return False
    if (b[0]=='0' and len(b)>1):
        return False
    if (c[0]=='0' and len(c)>1):
        return False

    # Check arithmetic equivalence
    if atoi(a) + atoi(b) == atoi(c):
        return True
    else:
        return False

def cryptToA(word, d):
    x = ''
    for c in word:
        x+=d[c]
    return x

def atoi(s):
    x = 0
    for c in s:
        d = ord(c)-ord('0')
        x = 10*x + d
    return x
        
crypt = ["SEND", "MORE", "MONEY"]
solution = [['O', '0'],
            ['M', '1'],
            ['Y', '2'],
            ['E', '5'],
            ['N', '6'],
            ['D', '7'],
            ['R', '8'],
            ['S', '9']]

crypt = ["TEN", "TWO", "ONE"]
solution = [['O', '1'],
            ['T', '0'],
            ['W', '9'],
            ['E', '5'],
            ['N', '4']]

print( isCryptSolution(crypt, solution) )
