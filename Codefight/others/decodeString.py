def decodeString(s):
    bracTable = dict()
    bracStack = []
    i = 0
    while i < len(s):
        if s[i] == "(":
            bracStack.append( i )
        if s[i] == ")":
            bracTabke[ bracStack.pop() ] = i
        i+=1


    i = 0
    while i < len(s):
        c = s[i]
        if c == "[":
            result = int(s[i-1]) * helper(s[i: bracTable[i]+1] )
            i = bracTable[i] + 1
##def decodeString(s):
##    bracTable = dict()
##    bracStack = []
##    i = 0
##    while i < len(s):
##        if s[i] == "(":
##            bracStack.append( i )
##        if s[i] == ")":
##            bracTabke[ bracStack.pop() ] = i
##        i+=1
##    print( bracTable )
##
##    return helper(s, 0, len(s)-1, bracTable)
##
##
##
##
##def helper(s, i, j, bracTable):
##    result = ''
##
##    while i <= j:
##        # Base case: no more bracket
##        if "[" not in s[i:j+1]:
##            result += s[i+1:j]
##            j+=1
##
##
##        # find the first digit
##        k = i
##        while s[i].isdigit() == False:
##            i+=1    
##        sL = s[k:i]
##
##        # extract digit
##        k = i
##        while s[i].isdigit():
##            i+=1
##        num = int(s[k:i]) # i is at "["
##
##        # build recurive result
##        result = sL + num * helper(s, i+1, bracTable[i]-1, bracTable)
##        i = bracTable[i]+1
##        
##    return result
##    
##
##s = "4[ab]"
##print( decodeString(s) )

    
    
    
