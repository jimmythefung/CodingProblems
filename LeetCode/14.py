def trie(s, trieD):
    new = trieD
    for letter in s:
        d = new
        new = d.setdefault(letter, dict())
    if len(s)==0:
        trieD[""] = dict()
    return trieD
        
def longestPre(arr):
    m = 1000
    d = dict()
    for s in arr:
        trie(s, d)
        m = len(s) if len(s) < m else m
    output = ""
    i = 0
    while True:
        if i == m:
            return output
        elif len(d.keys()) == 1:
            k = d.keys()[0]
            output += k
            d = d[k]
        else:
            return output
        i += 1

def longestPre2(arr):
    if len(arr) < 1:
        return ""
    ref = arr[0]
    output = ""
    ssLength = 1
    while True: #check for empty
        for word in arr:
            if len(word) < ssLength:
                return output
            elif ref[:ssLength] != word[:ssLength]:
                return output
            else:
                pass
        output = ref[:ssLength]
        ssLength += 1
        
#arr = ["nonobvious", "nonfiction", "nontoxic"]
arr = ['a', "aa"]
print longestPre(arr)

