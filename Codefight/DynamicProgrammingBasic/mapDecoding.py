def mapDecoding(message):
    cache = {}
    rDecode(message, cache)
    return cache[message]%1000000007

def rDecode(s, cache):
    # Base and corner cases
    if s in cache:
        return cache[s]
    if len(s)==2:
        if s[0] == '0':
            cache[s] = 0
        else:
            cache[s] = 2 if int(s)<=26 and s[1]!='0' else 1
        return cache[s]
    if len(s)==1:
        cache[s] = 1 if s!='0' else 0
        return cache[s]
    if len(s)==0:
        cache[s] = 1
        return cache[s]

    # first: first letter plus the result of remaining string
    if s[0] == '0':
        first = 0
    else:
        first = rDecode(s[1:], cache)

    # second: first 2 letters plus the result of remaining string
    second = 0
    if int(s[:2]) <= 26:
        if s[0]!='0' and s[:2] != '00':
            second = rDecode(s[2:], cache)

    # combine result
    cache[s] = first + second
    return cache[s]

message = "10122110"
print( mapDecoding(message) )
