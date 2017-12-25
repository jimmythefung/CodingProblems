def letterComb(s):
    d = dict()
    d['2'] = list('abc')
    d['3'] = list('def')
    d['4'] = list('ghi')
    d['5'] = list('jkl')
    d['6'] = list('mno')
    d['7'] = list('pqrs')
    d['8'] = list('tuv')
    d['9'] = list('wxyz')

    return rComb(s, d)

def rComb(s,d):
    arr = []
    if len(s) == 0:
        return arr
    if len(s) == 1:
        for letter in d[ s[0] ]:
            arr += [letter]
        return arr

    for c in d[ s[0] ]:
        for x in rComb(s[1:], d):
            arr += [c+x]
    return arr

s = "234"
print letterComb(s)
