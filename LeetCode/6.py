def zz(s, nRow):
    if nRow < 2:
        return s
    rows = [""]*nRow
    end_of_row = len(rows)-1
    
    i = -1
    go_forward = True
    for letter in s:
        # Check bondary
        if i==0:
            go_forward = True
        if i==end_of_row:
            go_forward = False
        if go_forward:
            i += 1
        else:
            i -= 1
        rows[i] += letter  

    return "".join(rows)
        

        
def zz2(s, nRow):
    if nRow < 2:
        return s
    
    output = ""
    r = [[] for i in range(nRow)]
        
    end_of_row = len(r)-1
    
    i = -1
    go_forward = True
    for letter in s:
        # Check bondary
        if i==0:
            go_forward = True
        if i==end_of_row:
            go_forward = False
        if go_forward:
            i += 1
        else:
            i -= 1
        r[i].append(letter)

    for row in r:
        output += "".join(row)
    return output    

#convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
s = "PAYPALISHIRING"
s2 = "ABC"
print zz2(s, 3)
print zz2(s2, 2)
