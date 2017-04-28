def longest(s):
    if len(s)==0:
        return 0
    r = [0, 0]
    a = 0
    b = 1

    seen = dict()
    seen[s[a]] = [a]

    while b < len(s):
        if s[b] not in seen:
            seen[s[b]] = [b]
        else:
            a = seen[s[i]][-1]+1
            seen[s[b]].append(b)
        
        if b-a > r[1]-r[0]:
            r = [a, b]
        b+=1
    return s[r[0]:r[1]+1]

s = "abba"
print longest(s)
