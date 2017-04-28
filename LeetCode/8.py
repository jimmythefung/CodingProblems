def atoi(s):
    result = 0
    for letter in s:
        result = result*10 + (ord(letter)-ord("0"))
    return result

def itoa(x):
    s = ""
    i = 0
    while x != 0:
        i += 1
        s = chr( x%10+ord("0") ) + s
        x = x/10
        if i%3==0 and x!=0:
            s = ","+s
            i = 0
    return s

# 295317441 to "295,317,441"
s = 295317441
print itoa(s)
