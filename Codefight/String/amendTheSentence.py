def amendTheSentence(s):
    result = ""
    start = 0
    for ind, c in enumerate(s):
        if c.isupper():
            result = result+" "+s[start:ind].lower()
            start = ind
            
    result = result+" "+s[start:].lower()
    return result.strip()

s = "CodefightsIsAwesome"
print( amendTheSentence(s) )
