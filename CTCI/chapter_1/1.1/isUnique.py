# Implement an algorithm to determine if a string has all unique characters.
#   What if you cannot use additional data structure

def isUnique(s):
    j = 0
    for e in s:
        j = j + 1
        i = j
        while i<len(s):
            if s[i]==e:
                return False
            i = i + 1
    return True

def main():
    sT = "acbb"
    print sT, "isUnique?", str(isUnique(sT))
    sF = "dcba"
    print sF, "isUnique?", str(isUnique(sF))

if __name__ == "__main__":
    main()
