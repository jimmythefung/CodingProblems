def mapDecoding(message):
    fibCache = {}
    return fibSolve(message, fibCache)%1000000007

def fibSolve(s, fibCache):
    # Base case: size 0
    if len(s)==0:
        return 1

    # Base case: size 1
    if s[0]=='0':
        fibCache[0] = 0
    else:
        fibCache[0] = 1
    if len(s) == 1:
        return fibCache[0]

    # Base case: size 2
    if s[1]=='0':
        fibCache[1] = 1 if int(s[0:2])<=26 else 0
    else:
        if s[0]=='0':
            fibCache[1] = 1
        else:
            fibCache[1] = 2 if int(s[0:2])<=26 else 1

    # Case size 3 and higher
    i = 2
    while i < len(s): # Note: i-1 -> keep last char, whereas i-2 -> keep last 2 chars
        # Determine i-1
        if s[i]!='0':
            i_1 = fibCache[i-1]
            # Determine i-2
            if s[i-1]=='0': # case 0x
                i_2 = 0
            else:			# case yx
                if int(s[i-1:i+1]) <= 26:
                    i_2 = fibCache[i-2]
                else:
                    i_2 = 0
        else:
            i_1 = 0
            # Determine i-2
            if s[i-1]=='0':	# case '00'
                    i_2 = 0
            else:			# case 'y0'
                if int(s[i-1:i+1]) <= 26:
                    i_2 = fibCache[i-2]
                else:
                    i_2 = 0

        fibCache[i] = i_1 + i_2
        i+=1

    return fibCache[ len(s)-1 ]

print(mapDecoding("123"))
