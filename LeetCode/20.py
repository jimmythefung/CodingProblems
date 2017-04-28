#Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
#The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.


def validParen(s):
    OP = {'(':')', '{':'}',  '[':']',}
    CL = {')':'(', '}':'{',  ']':'[' }
    stack = []
    for ch in s:
        if ch in OP:
            stack.append(ch)
        if ch in CL:
            if len(stack)!=0 and stack[-1]==CL[ch]:
                stack.pop()
            else:
                return False
    if len(stack)!=0:
        return False
    else:
        return True
        

s = '([ab]c){'
print validParen(s)
