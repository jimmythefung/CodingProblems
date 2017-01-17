def answer(start, length):
    a = 0
    b = 0
    xorResult = 0
    for row in range(length):
        a = start + length*row
        width = length - row -1
        b = a + width

        if a!=b:
            xorResult ^= rangeXor(a,b)
        else:
            xorResult ^= b

    return xorResult

# I was starting to find a pattern for "exclusively-or"ing (xor's) a sequence of integers to come up with a O(1) answer,
# but I couldn't make out the final form
# Ultimately, I learned and fully understood the code and borrowed it from here. This gives robust O(1) runtime:
#   http://stackoverflow.com/questions/10670379/find-xor-of-all-numbers-in-a-given-range
#

def rangeXor(a, b):
    # rangeXor(a, b) = a^...^...^b = (0^...^(a-1)^a^...^b)^(0^...^(a-1))
    return Xor(b)^Xor(a-1)

# Xor(b) = 0^1^...^b
def Xor(b):
    pattern = [b, 1, b+1, 0]
    return pattern[b%4]

print answer(0, 3)
print answer(17, 4)
print answer(0, 40000)
