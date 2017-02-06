class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        return longestLength(s)
        
def longestLength(s):
    if s == "":
        return 0
    else:
        result = [0, 0]
        cache = dict()
        helper(s, 0, len(s)-1, result, cache)
        return (result[1] - result[0]) + 1

def helper(s, start, end, result, cache):
    # Base case
    if start==end:
        myS = set()
        myS.add(s[end])
        cache[(start, end)] = [True, myS]
        return cache[(start, end)]

    # Trim leftward
    if (start, end-1) in cache:
        l = cache[(start, end-1)]
    else:
        l = helper(s, start, end-1, result, cache)


    # Trim rightward
    if (start+1, end) in cache:
        r = cache[(start+1, end)]
    else:
        r = helper(s, start+1, end, result, cache)

    if l[0] == True:
        if s[end] not in l[1]:
            l[1].add(s[end])
            l[1].add(s[start])
            if (result[1]-result[0]) < (end-start):
                result[0] = start
                result[1] = end
            cache[(start, end)] = l
            return [True, l[1]]
    return [False]

s = "ejtdfngsdnnkgpkvtigsq"
print longestLength(s)
