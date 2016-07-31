# Given two string s1, s2. Return if the two strings are permutation of each other
def isPerm(s1, s2):

    # Can't be permutation if length differ
    if len(s1) != len(s2):
        return False

    # frequency count of characters in s1
    d1 = dict()
    for c1 in s1:
        if c1 in d1:
            d1[c1] += 1
        else:
            d1[c1]  = 1

    # frequency count of characters in s2
    d2 = dict()
    for c2 in s2:
        if c2 in d2:
            d2[c2] += 1
        else:
            d2[c2] = 1


    # Compare dictionaries
    for c2 in s2:
        if d2[c2] != d1[c2]:
            return False
    return True



s1 = 'abc'
s2 = 'cba'
print "Is "+s1+" a permutation of "+s2+"?",isPerm('abc', 'cba')
