def decodeString(s):
    closebrac = dict()
    q = []

    # Build a dictionary that gives the index of closing bracket
    for i, c in enumerate(s):
        if c == "[":
            q.append( i )
        if c == "]":
            closebrac[ q.pop() ] = i

    # helper function that solves the problem. start and end excludes brackets
    return expand(s, 0, len(s)-1, closebrac)



def expand(s, start, end, closebrac):
    i = start
    result = ''
    while i <= end:
        
        # Base case: pure text (no brackets)
        substring = s[i:end+1]
        if "[" not in substring:
            result += substring
            return result        

        # find the start of digit
        a = i
        while s[i].isdigit()==False:
            i+=1

        # extract digit
        b = i
        while s[i].isdigit():
            i+=1
        k = int(s[b:i])
        result += s[a:b] + k*expand(s, i+1, closebrac[i]-1, closebrac)

        # continue on at 1 after the closed bracket
        i = closebrac[i]+1

    return result
        
        
    
    
s = "z1[y]zzz2[abc]"
s = "sd2[f2[e]g]i"
print( decodeString(s) )

# Good idea! Using timing and stack to represent recursion depth
def decodeString_chris_hunt(s):
    str_stack = [[]]
    times_stack = []
    cur_times = ""
    for c in s:
        if ord(c) in range(48,58):
            cur_times += c
        elif c == '[':
            times_stack.append(int(cur_times))
            str_stack.append([])
            cur_times = ""
        elif c == ']':
            cur_str = "".join(str_stack.pop())
            str_stack[-1].append(cur_str * times_stack.pop())
        else:
            str_stack[-1].append(c)
    return "".join(str_stack.pop())
