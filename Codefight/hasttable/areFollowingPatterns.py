##def areFollowingPatterns(strings, patterns):
##    n = len(strings)
##    i = 0
##    while i < n:
##        j = i+1
##        while j < n:
##            if ((strings[i] == strings[j]) and (patterns[i] != patterns[j])) == True:
##                return False
##            if ((strings[i] != strings[j]) and (patterns[i] == patterns[j])) == True:
##                return False
##            j+=1
##        i+=1
##    return True

def areFollowingPatterns(strings, patterns):
    d = {}
    for s, p in zip(strings, patterns):
        if s not in d:
            d[s] = p
        else:
            if d[s] != p:
                return False
    return len(d) == len( set(d.values) )
    
            
strings = ["cat", "dog", "dog"]
patterns = ["a", "b", "b"]
print( areFollowingPatterns(strings, patterns) )

# This is why function can't simply return true but check for len in uniquenss
strings = ["cat", "dog", "rat"]
patterns = ["a", "b", "b"]
print( areFollowingPatterns(strings, patterns) )
