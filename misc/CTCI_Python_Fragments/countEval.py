from collections import deque

def countEval(s, result):
    expSet = expPermHelper(s) # expSet = ["(a)&(b)&(c)", "((a)&(b))&(c)", "(a)&((b)&(c))"]
    count = 0
    for exp in expSet:
        if eval(exp) == result:
            print exp, "->", result
            count += 1
    return count

def expPermHelper(s): # The helper makes sure the expSet do not have dups
    expSet = expPerm(s) # i.e. ((a)&(b)) is dup of (a)&(b)
    dups = set()
    for exp in expSet:
        dups.add(parenthesize(exp))
    unique = []
    for exp in expSet:
        if exp not in dups:
            unique.append(exp)
    return unique

def expPerm(s): # s = "a&b&c"
    if len(s) == 1:
        return [parenthesize(s)] # s = "c"
                            
    expSet = expPerm(s[2:]) # we keep "a&" and pass in "b&c", recursively, keep "b&" pass "c" 
    result = []
    opEnd = parenthesize(s[0])   # opEnd = "(a)"
    op = s[1]                    # op = "&"

    for exp in expSet:           # expSet = ["(b)&(c)", "((b)&(c))"]
        terms, n = parseExp(exp) # if exp = "(b)&(c)", then terms = ["(b)", "&", "(c)"]
        i = 0
        while i <= n:
            L, R = getTerms(terms, i)        # i.e. terms = ["(b)", "&", "(c)"]
            if i == 0:                       # if i = 0, then L = "" and R = "(b)&(c)"
                newTerm = opEnd + op + R     # newTerm = "(a)" + "&" + "(b)&(c)"
            else:                                               # if i = 1, then L = "(b)" and R = "&(c)"
                newTerm = parenthesize(opEnd + op + L) + R      # newTerm = ("(a)" + "&" + "(b)") +"&(c)"
            result.append(newTerm)
            i += 1
    return result
    
def getTerms(terms, n):
    j = 0
    s = ""
    while j < 2*n-1 and j < len(terms):
        s += terms[j]
        j += 1
    return s, "".join(terms[j:])  # if terms = ["(b)", "&", "(c)"], n = 1, then L = "(b)" and R = "&(c)"
                    

def parseExp(s): # i.e. parseExp("(a)&((b)&(c))&(d)") = ["(a)", "&", "((b)&(c))", "(d)"]; we split the outter-most operends.
    stack = []      # each element, regardless of nested parenthesis, is called terms: "(a)", "((b)&(c))", ...etc
    terms = []
    operators = ["|", "&", "^"]

    i = 0
    termStringQ = deque()
    while i < len(s):
        stack.append(s[i]) 
        if stack[-1] == ")":                     # stack: ( ( a )
            operend = ""
            while stack[-1] != "(":                    
                operend = stack.pop() + operend  # operend =  a)
            operend = stack.pop() + operend      # operend = (a)

            if operend!="()":
                termStringQ.append(operend)      # termStringQ:  (...)
            else:                                # termStringQ:  (...), &, (...), &, (...) 
                termStringQ.appendleft("(")      # termStringQ: ((...), &, (...), &, (...) 
                termStringQ.append(")")          # termStringQ: ((...), &, (...), &, (...))

        elif stack[-1] in operators:
            if len(stack) != 0:
                termStringQ.append(stack.pop()) # termStringQ:  (...), &
            else:
                terms.append(stack.pop())

        if len(stack) == 0:
            termString = ""
            while len(termStringQ)!=0:                  # termStringQ:  (, (...), &, (...), &, (...), )
                termString += termStringQ.popleft()     
            terms.append(termString)                    # termString = "((...)&(...)&(...))"
            
        i+=1

    # determine number of terms
    n = 0
    operators = ["|", "&", "^"]
    for t in terms:
        if t not in operators:
            n += 1
            
    return terms, n

def parenthesize(s):
    return "("+s+")"

s = "1^0|0|1"
print countEval(s, 0)

s = "0&0&0&1^1|0"
print countEval(s, 1)

