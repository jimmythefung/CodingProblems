class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        return longest(s)
        
def longest(s):
    if len(s)==0:
        return 0
    r = [0, 0]
    a = 0
    b = 1

    seen = dict()
    seen[s[a]] = a

    while b < len(s):
        if s[b] not in seen:
            seen[s[b]] = b
        else:
            if a < seen[s[b]] + 1:
                a = seen[s[b]] + 1
            seen[s[b]] = b
        
        if b-a > r[1]-r[0]:
            r = [a, b]
            
        b+=1

    return r[1]-r[0]+1
