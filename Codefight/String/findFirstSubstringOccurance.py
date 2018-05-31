def findFirstSubstringOccurrence(s, x):
    hashed = set()
    hashed.add(x)
    
    start = 0
    end = len(x)

    while end <= len(s):
        if s[start:end] in hashed:
            return start
        start+=1
        end+=1
        
    return -1

s = "CodefightsIsAwesome"
x = "IsA"
print( findFirstSubstringOccurrence(s, x) )
