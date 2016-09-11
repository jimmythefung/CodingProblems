def powerSet(S):
    output = []
    for e in S:
        size = len(output)
        for i in range(size):
            o = output[i]
            output.append(e+o)
        output.append(e)
    output.append(" ")
    return output


S = "abc"
print powerSet(S)
