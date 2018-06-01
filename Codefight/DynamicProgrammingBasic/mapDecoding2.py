def mapDecoding(message):
    if len(message) == 1:
        return 1 if message!='0' else 0
    if len(message) == 0:
        return 1
    
    tot = 0
    last_sol = []
    last_sol.append( [message[0]] )
    level = 1
    while level < len(message):
        new_sol = []
        val = message[level]
        if val != '0':
            for item in last_sol:
                # case 1: pure append
                new_sol.append( item + [val] )

                # case 2: combine with last item
                lastItem = item[-1]+val
                if int( lastItem ) <= 26:
                    new_sol.append( item[:-1] + [lastItem] )
        
            tot = len(new_sol)
            last_sol = new_sol[:]
            level += 1
        else:
            return 0
    
    return tot

message = "123"
print( mapDecoding(message) )
