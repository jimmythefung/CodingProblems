def perm(s): # permutation
    if len(s) == 0:
        return ['']

    output = []
    for i in range(len(s)):
        pick = s[i]
        rest = s[:i] + s[i+1:] # each iteration, rest is 1 element less at s[i].
        for x in perm(rest):
            output.append(pick + x)
    return output


def subset(s, n): # permutation with length constraint
    if len(s)==0 or n==0:
        return ['']

    output = []
    for i in range(len(s)):
        pick = s[i]
        rest = s[:i] + s[i+1:]      # each iteration, rest is 1 element less at s[i].
        for x in subset(rest, n-1): # n-1 causes length constraint; recursion depth at most n
            output.append(pick + x) #  and recursion depth == length of x
    return output

def combo(s, n): # permutation with length and repetition constrains
    if len(s)==0 or n==0:
        return ['']

    output = []
    for i in range(len(s)-n+1): # if len(s)==n, proceed just once
        pick = s[i]             # Guaranteeds solution contains pick
        rest = s[i+1:]          # Repetition constraints: Pick already processed so rest excludes s[:i]
        for x in combo(rest, n-1):
            output.append(pick+x)
    return output

print "Permutation:", perm('abc')
print "Combination:", combo('abc', 2)
print "Subset     :", subset('abc', 2)
