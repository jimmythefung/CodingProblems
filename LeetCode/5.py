def palSub(s):
    cache = dict()
    longest = s[0]
    i = 0
    while i < len(s):
        char = s[i]
        if char not in cache:
            cache[char] = [i]
        else:
            for ind in cache[char]:
                newS = s[ind:i+1]
                if len(newS) >= len(longest):
                    if (checkPal(newS)):
                        longest = newS
                else:
                    break
                
            cache[char].append(i)
        i += 1
    return longest

def checkPal(s):
    start = 0
    end = len(s)-1
    while start < end:
        if s[start] == s[end]:
            start += 1
            end -= 1
        else:
            return False
    return True


s = "12321"
s2 = "babadada" #a
print palSub(s2)

##def palSub(s):
##    sol = [s[0]]
##    helper(s, sol)
##    return sol[0]
##
##def helper(s, sol):
##    # base case - no need to check if short
##    if len(s) < len(sol[0]):
##        return
##
##    # regular case. Always recurse first!
##    helper(s[:-1], sol)
##    helper(s[1:], sol)
##    if s[0]==s[-1]:
##        if (checkPal(s)) and len(s)>len(sol[0]):
##            sol[0] = s        
##
