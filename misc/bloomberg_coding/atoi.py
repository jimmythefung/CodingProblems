# e.g., a = '341' -> 341
def atoi(a):
    tot = 0
    for d in a:
        x = ord(d)-ord('0')
        tot = tot*10 + x
    return tot

# test 1
a = '341'
print( atoi(a) )
